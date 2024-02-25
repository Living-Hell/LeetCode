// M1
// Using hashmap
// Faster than 46.41% (4ms)

class Solution
{
public:
    unordered_map<string, string> mp;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string shortURL = "http://tinyurl.com/" + to_string(mp.size());
        mp[shortURL] = longUrl;
        return shortURL;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));