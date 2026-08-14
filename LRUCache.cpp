#include <unordered_map>
using namespace std;

//双向链表节点
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _val): key(_key), value(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;

    //把节点加到虚拟头后面（最近使用位置）
    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    //摘下链表中某一个节点
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    //把已有节点移动到头部
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    //删除tail前面的节点（最久未使用），返回该节点
    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        size = 0;
        //虚拟头、虚拟尾，不用判空边界
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DLinkedNode* node = cache[key];
        moveToHead(node); //访问后更新为最近使用
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            //key已存在：更新value，移到头部
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }else{
            //新建节点
            DLinkedNode* newNode = new DLinkedNode(key, value);
            cache[key] = newNode;
            addToHead(newNode);
            size++;
            //超过容量，淘汰最久未使用
            if(size > capacity){
                DLinkedNode* delNode = removeTail();
                cache.erase(delNode->key);
                delete delNode;
                size--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

