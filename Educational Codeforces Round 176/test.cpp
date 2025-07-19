
    sort(begin(arr), end(arr));
    auto f = [&](ll x) { return distance(begin(arr), lower_bound(begin(arr), end(arr), x)); };
