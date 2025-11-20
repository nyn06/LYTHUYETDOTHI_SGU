#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        map<string, int>dem; // luu so lan xuat hien cua tung bo ba
        int maxx = 0;

        // duyet qua tat ca bo ba
        for (int i = 0; i + 2 < (int)s.size(); i++)
        {
            string boBa = s.substr(i, 3); // lay ra 3 ky tu lien tiep
            dem[boBa]++; // tang tan suat
            if (dem[boBa] > maxx) {
                maxx = dem[boBa]; // cap nhat ket qua lon nhat
            }
        }
        cout << maxx << "\n";
    }
    return 0;
}
