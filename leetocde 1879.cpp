 istringstream iss(s);
        string word;
        vector<string> words(9);

        while (iss >> word) {

            int pos = word.back() - '0';

            word.pop_back();

            words[pos - 1] = word;
        }


       string result;
        for (const auto& w : words) {
            if (!w.empty()) {
                if (!result.empty()) result += ' ';
                result += w;
            }
        }

        return result;
    }
};
