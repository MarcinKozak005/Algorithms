#include <iostream>
#include <string>
#include <cstdint> // uintptr_t
#include <bits/stdc++.h> // find()
#include <list>

using namespace std;

template <class K, class V>
class HashMap
{
    static double constexpr loadFactor = 0.75;
    list<pair<K,V>>* table = new list<pair<K,V>>[16];
    int size = 0;
    int capacity = 16;

    public:
    void add(K key,V val)
    {
        if(double(size/capacity) <= loadFactor)
        {
            table[hash(key)].push_back(*new pair<K,V>(key,val));
            size++;            
        }
        else
        {
            int oldCapacity = capacity;
            capacity *= 2;
            list<pair<K,V>>* tmp = new list<pair<K,V>>[capacity];

            for(int i=0; i<oldCapacity; i++)
            {
                for(auto elem: table[i])
                    (*(tmp+hash(elem.first))).push_back(*new pair<K,V>(key,val));
                table[i].clear();
            }
            delete table;
            *table = *tmp;
            add(key,val);
        }
    }

    V get(K key)
    {
        for(pair<K,V> p: table[hash(key)])
            if(p.first == key) return p.second;
        return NULL;
    }

    void remove(K key)
    {
        V valueBeforeRemove = get(key);
        table[hash(key)].remove_if([key](pair<K,V> p){ return p.first == key; });
        if(valueBeforeRemove != get(key)) size --;
    }

    int hash(K key)
    {
        return uintptr_t(&key)%this->capacity;
    }

    int getSize()
    {
        return size;
    }

};


int main()
{
    HashMap<string,int> map;
    cout<<"Map size: "<<map.getSize()<<endl;
    map.add("one",1);
    map.add("two",2);
    map.add("three",3);
    map.add("four",4);
    map.add("five",5);
    cout<<"After add"<<endl;
    cout<<"Map size: "<<map.getSize()<<endl;
    cout<<endl;
    cout<<"'four': "<<map.get("four")<<"\n";
    cout<<"'seven': "<<map.get("seven")<<"\n";
    cout<<endl;
    cout<<"Remove 'four'"<<endl;
    map.remove("four");
    cout<<"'four': "<<map.get("four")<<"\n";
    cout<<"Map size: "<<map.getSize()<<endl;
    
    return 0;
}