class Solution {
public:
    int takeCharacters(string s, int k) {
        if(s.length() < (3*k)) return -1;
        vector<int> c = find_char(s, k, 'c');
        vector<int> b = find_char(s, k, 'b');
        vector<int> a = find_char(s, k, 'a');
        if(c.size() == 0 or b.size() == 0 or a.size() == 0) return -1;
        int front_dis = max(c[0], max(b[0], a[0]));
        int back_dis = max(c[1], max(b[1], a[1]));
        return (front_dis + back_dis);
    }
    vector<int> find_char(string s, int k, char ch){
        vector <int> front_posi, back_posi;
        pair<int, int> both_posi; // pair<front posi, back posi>
        int posiSum;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == ch){
                front_posi.push_back(i);
                back_posi.push_back(s.length() - i);
            }
            if(front_posi.size() == k)break;
        }
        if(front_posi.size()<k) return {};
        posiSum = s.length() +1;
        for(int i = 0; i<k; i++){
            if((front_posi[i] + back_posi[k-i-1])<(posiSum)){
                both_posi = make_pair(front_posi[i], back_posi[k-i-1]);
                posiSum = front_posi[i] + back_posi[k-i-1];
            }
        }
        if((back_posi.back())<(posiSum)){
            both_posi = make_pair(-1, back_posi.back());
            posiSum = back_posi.back();
        }
        if((front_posi.back())<(posiSum)){
            both_posi = make_pair(front_posi.back(), -1);
            posiSum = front_posi.back();
        }
        return {both_posi.first, both_posi.second};
    }
};
