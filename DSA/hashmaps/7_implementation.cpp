#include <iostream>
using namespace std;

template <typename T>

class mapNode{
    public:
    string key;
    T value;
    mapNode * next;

    mapNode(string key , T value){
        this->key=key;
        this->value=value;
        this->next=NULL;
    }

    ~mapNode(){
        delete next;
    }
};

template <typename T>
class ourMap{
    mapNode<T> ** buckets;
    int size;
    int numBuckets;

    public:
    ourMap(){
        size=0;
        numBuckets=5;
        buckets = new mapNode<T>*[numBuckets];
        for (int i=0 ; i<numBuckets ; i++){
            buckets[i]=NULL;
        }
    }

    ~ourMap(){
        for (int i=0 ; i<numBuckets ; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }

    int count(){
        return this->size;
    }

    void rehash(){
        mapNode<T> ** temp = buckets;
        buckets = new mapNode<T>*[2*numBuckets];
        for (int i=0 ; i<2*numBuckets ;i++){
            buckets[i]=NULL;
        }
        int oldBucketsCount = numBuckets;
        numBuckets *= 2;
        size = 0;
        for (int i=0 ; i<oldBucketsCount ; i++){
            mapNode<T> * head = temp[i];
            while (head!=NULL){
                string key = head->key;
                T value = head->value;
                insert(key,value);
                head=head->next;
            }
        }

        for (int i=0 ; i<oldBucketsCount ; i++){
            mapNode<T> * head = temp[i];
            delete head;
        }
        delete [] temp;
    }

    public:
    double getLoadFactor(){
        return (1.0*size)/numBuckets;
    }

    private:
    int getBucketIndex(string key){
        int hashCode=0;
        int currentCoefficient = 1;
        for (int i=key.length()-1 ; i>=0 ; i--){
            hashCode+= key[i]*currentCoefficient;
            hashCode = hashCode % numBuckets;
            currentCoefficient *= 37;
            currentCoefficient = currentCoefficient % numBuckets;
        }

        return hashCode%numBuckets;
    }

    public:
    void insert(string key , T value){
        int bucketIndex = getBucketIndex(key);
        mapNode<T> * head = buckets[bucketIndex];
        while (head != NULL){
            if (head->key==key){
                head->value = value;
                return;
            }
            head=head->next;
        }
        head = buckets[bucketIndex];
        mapNode<T> *  node = new mapNode<T>(key , value);
        node->next=head;
        buckets[bucketIndex]=node;
        size++;
        double loadFactor = (1.0*size)/numBuckets;
        if (loadFactor>0.7){
            rehash();
        }
    }

    T remove(string key){
        int bucketIndex = getBucketIndex(key);
        mapNode<T> * head = buckets[bucketIndex];
        mapNode<T> * prev = NULL;
        while (head!=NULL){
            if (head->key==key){
                if (prev==NULL){
                    buckets[bucketIndex]=head->next;
                }
                else{
                   prev->next=head->next; 
                }
                T value = head->value;
                head->next=NULL; //so that destructor is not called
                delete head;
                size--;
                return value;
            }
            prev=head;
            head=head->next;
        }
        return 0;
    }

    T getValue(string key){
        int bucketIndex = getBucketIndex(key);
        mapNode<T> * head = buckets[bucketIndex];
        while (head != NULL){
            if (head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }
};

int main()
{
    ourMap<int>  map;
    for (int i=0 ; i<10 ; i++){
        char c = '0'+i;
        string key = "abc";
        key = key + c;
        int value = i+1;
        map.insert(key,value);
        cout<<map.getLoadFactor()<<endl;
    }

    cout<<map.count()<<endl;
    map.remove("abc2");
    map.remove("abc7");
    cout<<map.count()<<endl;

    for (int i=0 ; i<10 ; i++){
        char c = '0'+i;
        string key = "abc";
        key = key + c;
        cout<<key<<" : "<<map.getValue(key)<<endl;
    }

    cout<<map.count()<<endl;
    return 0;
}