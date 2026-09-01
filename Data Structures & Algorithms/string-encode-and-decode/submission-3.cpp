class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_str = "";

        for (string s : strs) {
            encoded_str += to_string(s.size()) + '#' + s;
        }

        return encoded_str;
    }

    vector<string> decode(string s) {
        vector<string> tokens;

        int i = 0;
        while (i < s.size()) {
            int j = i;
            string num_chars = "";

            while (s[j] != '#') {
                num_chars += s[j];
                j++;
            }

            int size = stoi(num_chars);

            // j is at #
            j++;

            string token = "";
            for (int k = 0; k < size; k++) {
                token += s[j + k];
            }

            tokens.push_back(token);
            i = j + size;
        }
        return tokens;
    }
};
