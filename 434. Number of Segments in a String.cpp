    int countSegments(string s) {
        if(s == "") return 0;
        int blank =0;
        int non_blank=0;
        for(auto c : s)
        {
            if(c == ' ' && non_blank)
            {
                ++blank;
                non_blank=0;
            }
            if (c != ' ') ++non_blank;
        }
        if(non_blank) ++blank;
        return blank;
    }
