void StringReplace(string& strBase, string strSrc, string strDes) {
    string::size_type pos = 0;
    string::size_type srcLen = strSrc.size();
    string::size_type desLen = strDes.size();
    pos = strBase.find(strSrc, pos);
    while ((pos != string::npos)) {
        strBase.replace(pos, srcLen, strDes);
        pos = strBase.find(strSrc, (pos + desLen));
    }
}

class Solution {
public:
    string entityParser(string text) {
        StringReplace(text, "&quot;", "\"");
        StringReplace(text, "&apos;", "'");
        StringReplace(text, "&gt;", ">");
        StringReplace(text, "&lt;", "<");
        StringReplace(text, "&frasl;", "/");
        StringReplace(text, "&amp;", "&");
        return text;
    }
};