
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
void BIG_NUM_MUL(unsigned long in[5], unsigned long out[6], unsigned long factor) {
	//based on TTMath library by Tomasz Sowa.

	unsigned long src[5] = {0};
	for (int i = 0; i < 5; i++)
		src[i] = ((in[4 - i] >> 24) | ((in[4 - i] << 8) & 0x00FF0000) | ((in[4 - i] >> 8) & 0x0000FF00) | (
		              in[4 - i] << 24));

	unsigned long long tmp = 0;

	tmp = static_cast<unsigned long long>(src[0]) * static_cast<unsigned long long>(factor);
	out[0] = tmp & 0xFFFFFFFF;
	out[1] = tmp >> 32;
	tmp = static_cast<unsigned long long>(src[1]) * static_cast<unsigned long long>(factor) + static_cast<unsigned long long>(out[1]);
	out[1] = tmp & 0xFFFFFFFF;
	out[2] = tmp >> 32;
	tmp = static_cast<unsigned long long>(src[2]) * static_cast<unsigned long long>(factor) + static_cast<unsigned long long>(out[2]);
	out[2] = tmp & 0xFFFFFFFF;
	out[3] = tmp >> 32;
	tmp = static_cast<unsigned long long>(src[3]) * static_cast<unsigned long long>(factor) + static_cast<unsigned long long>(out[3]);
	out[3] = tmp & 0xFFFFFFFF;
	out[4] = tmp >> 32;
	tmp = static_cast<unsigned long long>(src[4]) * static_cast<unsigned long long>(factor) + static_cast<unsigned long long>(out[4]);
	out[4] = tmp & 0xFFFFFFFF;
	out[5] = tmp >> 32;

	for (int i = 0; i < 12; i++) {
		unsigned char temp = reinterpret_cast<unsigned char *>(out)[i];
		reinterpret_cast<unsigned char *>(out)[i] = reinterpret_cast<unsigned char *>(out)[23 - i];
		reinterpret_cast<unsigned char *>(out)[23 - i] = temp;
	}
}
// thanks to raksamp devs!
int gen_gpci(char buf[64], unsigned long factor) {
	unsigned char out[6 * 4] = {0};

	static const char alphanum[] =
	    "0123456789"
	    "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < 6 * 4; ++i)
		out[i] = alphanum[rand() % (sizeof(alphanum) - 1)];


	out[6 * 4] = 0;

	BIG_NUM_MUL((unsigned long *) out, (unsigned long *) out, factor);

	unsigned int notzero = 0;
	buf[0] = '0';
	buf[1] = '\0';

	if (factor == 0) return 1;

	int pos = 0;
	for (int i = 0; i < 24; i++) {
		unsigned char tmp = out[i] >> 4;
		unsigned char tmp2 = out[i] & 0x0F;

		if (notzero || tmp) {
			buf[pos++] = (char) ((tmp > 9) ? (tmp + 55) : (tmp + 48));
			if (!notzero) notzero = 1;
		}

		if (notzero || tmp2) {
			buf[pos++] = (char) ((tmp2 > 9) ? (tmp2 + 55) : (tmp2 + 48));
			if (!notzero) notzero = 1;
		}
	}
	buf[pos] = 0;

	return pos;
}

std::string generate_random_gpci(int length = 42, int factor = 1001) {
	// Ensure length is within the acceptable range and is odd
	if (length < 4 || length > 48 || length % 2 == 0) {
		throw std::invalid_argument("Length must be in the interval [4,48] and be odd.");
	}

	// Calculate the size of the number in bytes
	int byte_count = length / 2;

	// Calculate the top and base numbers for the given byte_count
	uint64_t top_number = std::pow(2, byte_count * 8);
	uint64_t base_number = std::pow(2, (byte_count - 1) * 8);
	uint64_t possibilities_count = top_number - base_number;

	// Calculate how many integers are multiples of factor
	possibilities_count /= factor;

	// Generate a random multiple index
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<uint64_t> dist(0, possibilities_count);
	uint64_t nth_multiple_index = dist(gen);

	// Find the first multiple of factor that is greater than or equal to base_number
	uint64_t first_multiple = base_number + factor;
	first_multiple -= first_multiple % factor;

	// Calculate the GPCI number
	uint64_t number = first_multiple + factor * nth_multiple_index;

	// Convert the number to uppercase hexadecimal
	std::stringstream ss;
	ss << std::uppercase << std::hex << number;

	return ss.str();
}

int main() {
	char auth_bs[4 * 16] = {0};
	gen_gpci(auth_bs, 0x3e9);
	std::cout << "Generated GPCI: " << auth_bs << std::endl;
	return 0;
}
