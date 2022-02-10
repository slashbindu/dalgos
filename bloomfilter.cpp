/* Implement a probablistic datastructure to check if an key existes in massica scale  datastore 
A simple and lightweight implementation of a Bloom filter.: TODO
   
   Hashing algorithm used	/murmur/jenkins/nfv NO ms5!
   https://en.wikipedia.org/wiki/Jenkins_hash_function
   https://github.com/PeterScott/murmur3
   Expected rate of false positives  ?
   CHECK https://findingprotopia.org/posts/how-to-write-a-bloom-filter-cpp/
*/
#include<murmur3.h>

using namespace std;
Class BloomFilter{
   int n; // Number of items expected to be stored in bloom filter
   int m; // size based on n & fp
   int hash_count;
   float fp_prob; //  False Positive probabilit
   vector<bool>  mbtarr;
   BloomFilter( int items_count, float fp){
     
      n = items_count
         //alse possible probability in decimal
      fp_prob = fp;
       // Size of bit array to use
      m =  get_size(n, fp_prob);
      mbtarr.reserve(m);
      hash_count = get_hash_count(m, n);
   }
   
   get_size(int n, float fp_prob){
      
      /*
         n : int number of items expected to be stored in filter
        fp_prob : float        False Positive probability in decimal
         Return the size of bit array(m) to used using
        following formula
        m = -(n * log(p)) / (log(2)^2)
         */
        m = -(n * math.log(p))/(math.log(2)**2)
        return int(m)
     }
   
   void get_hash(string key, uint32_t[] & hash){
      
      //uint32_t _hash[4];                /* Output for the hash */
      uint32_t seed = 42;              /* Seed value for hash */
      MurmurHash3_x86_32(key, key.length(), seed, hash);
       
   }
   
   int get_hash_count(int m, int n){
 
      /*  Return the hash function(k) to be used using         following formula
        k = (m/n) * lg(2)
 
        m : int
            size of bit array
        n : int
            number of items expected to be stored in filter*/
        k = (m/n) * math.log(2)
        return int(k)
   
   }
   
   addkey(string key){
      
      
      
   }
   
   check(string key){
      
      
   }
   


};
/*
include <bits/stdc++.h>
#define ll long long
using namespace std;
 
// hash 1
int h1(string s, int arrSize)
{
    ll int hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash + ((int)s[i]));
        hash = hash % arrSize;
    }
    return hash;
}
 
// hash 2
int h2(string s, int arrSize)
{
    ll int hash = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hash = hash + pow(19, i) * s[i];
        hash = hash % arrSize;
    }
    return hash % arrSize;
}
 
// hash 3
int h3(string s, int arrSize)
{
    ll int hash = 7;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash * 31 + s[i]) % arrSize;
    }
    return hash % arrSize;
}
 
// hash 4
int h4(string s, int arrSize)
{
    ll int hash = 3;
    int p = 7;
    for (int i = 0; i < s.size(); i++) {
        hash += hash * 7 + s[0] * pow(p, i);
        hash = hash % arrSize;
    }
    return hash;
}
 
 
// loookup operation
bool lookup(bool* bitarray, int arrSize, string s)
{
    int a = h1(s, arrSize);
    int b = h2(s, arrSize);
    int c = h3(s, arrSize);
    int d = h4(s, arrSize);
 
    if (bitarray[a] && bitarray[b] && bitarray
        && bitarray[d])
        return true;
    else
        return false;
}
 
// insert operation
void insert(bool* bitarray, int arrSize, string s)
{
    // check if the element in already present or not
    if (lookup(bitarray, arrSize, s))
        cout << s << " is Probably already present" << endl;
    else
    {
        int a = h1(s, arrSize);
        int b = h2(s, arrSize);
        int c = h3(s, arrSize);
        int d = h4(s, arrSize);
 
        bitarray[a] = true;
        bitarray[b] = true;
        bitarray = true;
        bitarray[d] = true;
 
        cout << s << " inserted" << endl;
    }
}
 
// Driver Code
int main()
{
    bool bitarray[100] = { false };
    int arrSize = 100;
    string sarray[33]
        = { "abound",   "abounds",       "abundance",
            "abundant", "accessible",    "bloom",
            "blossom",  "bolster",       "bonny",
            "bonus",    "bonuses",       "coherent",
            "cohesive", "colorful",      "comely",
            "comfort",  "gems",          "generosity",
            "generous", "generously",    "genial",
            "bluff",    "cheater",       "hate",
            "war",      "humanity",      "racism",
            "hurt",     "nuke",          "gloomy",
            "facebook", "geeksforgeeks", "twitter" };
    for (int i = 0; i < 33; i++) {
        insert(bitarray, arrSize, sarray[i]);
    }
    return 0;
}

*/
