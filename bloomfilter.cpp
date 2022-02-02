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
   int n;
   int m;
   int hash_count;
   float fp_prob;
   //std::bitset<m> mbarr
   bitarray<int> * p
   BloomFilter( int items_count, float fp){
     
      n = items_count
         //alse possible probability in decimal
      fp_prob = fp;
       // Size of bit array to use
      m =  get_size(n, fp_prob);
      hash_count = get_hash_count(m, n)
      std::bitset<m> b1
      
      /*
      items_count : int
            Number of items expected to be stored in bloom filter
        fp_prob : float             False Positive probability in decimal
       
        # False possible probability in decimal
        self.fp_prob = fp_prob
 
       
       
        # Bit array of given size
        self.bit_array = bitarray(self.size)
      
        # initialize all bits as 0
        self.bit_array.setall(0)
         */
   
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
   
   uint32_t* get_hash(string key, uint32_t[] & hash){
      
      //uint32_t _hash[4];                /* Output for the hash */
      uint32_t seed = 42;              /* Seed value for hash */
      MurmurHash3_x86_32(key, key.length(), seed, hash);
      return hash 
   
   }
   
   int get_hash_count(int m, int n){
 
      //  Return the hash function(k) to be used using         following formula
        /*k = (m/n) * lg(2)
 
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
