#include <bits/stdc++.h>
using namespace std;

int main()
{
	unordered_map<string, string> mymap;

	mymap = { { "Australia", "Canberra" },
			{ "U.S.", "Washington" },
			{ "France", "Paris" } };

	auto it = mymap.begin();

	int number = mymap.bucket(it->first);
	cout << "The bucket number of key " << it->first 
									<< " is " << number;

	return 0;
}

