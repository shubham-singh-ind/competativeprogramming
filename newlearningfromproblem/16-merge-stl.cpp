/*
Learning:
Given a, b sorted vector and c empty vector, task is to merge a and b to c in sorted order.
merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
*/

// sorting initial containers
sort(arr1.begin(), arr1.end());
sort(arr2.begin(), arr2.end());

// using merge() to merge the initial containers
merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr3.begin());
