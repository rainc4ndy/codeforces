int n;
	cin >> n;
	vector<ll> v(n);
	SegmentTree st(n);

	for (int i =0; i < n;i++) {
		cin >> v[i];
		st.modify(i, v[i]);
	}