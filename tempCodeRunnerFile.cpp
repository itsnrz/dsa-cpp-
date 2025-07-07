 cout << "original array : ";
    for (int val : a) cout << val << " ";

    // Library sort
    cout << "\n\n# Using library sort:";
    vector<int> b = sortColorslib(a);
    cout << "\nresult: ";
    for (int val : b) cout << val << " ";
    cout << "\noriginal : ";
    for (int val : a) cout << val << " ";

    // Count sort
    cout << "\n\n# Using counting sort:";
    vector<int> c = sortColorscount(a);
    cout << "\nresult: ";
    for (int val : c) cout << val << " ";
    cout << "\noriginal : ";
    for (int val : a) cout << val << " ";

    // Dutch National Flag
    cout << "\n\n# Using Dutch National Flag algorithm:";
    vector<int> d = sortColorsdutch(a);
    cout << "\nresult: ";
    for (int val : d) cout << val << " ";
    cout << "\noriginal : ";
    for (int val : a) cout << val << " ";
