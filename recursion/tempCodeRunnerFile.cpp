if (e == t.size()) {
        return;
    
}  
    if (s > e) {
        cout << endl;
        subarray(t, 0, e + 1);
    } 
    else {
        for (int i = s; i <= e; i++) {
            cout << t[i] << " ";
        }
        cout << endl;
        subarray(t, s + 1, e);
    }