#ifndef RING
#define RING

using namespace std;

template<typename Key, typename Value>
class Ring
{
private:
    struct Element
    {
        Key key;
        Value value;
        Element* next;
        Element* prev;
    };

    Element* head;
    Element* tail;

public:
    Ring() : head(nullptr), tail(nullptr) {}

    ~Ring()
    {
        remove_all();
    }

    void insertEnd(const Key& key, const Value& value)
    {
        Element* newElement = new Element;
        newElement->key = key;
        newElement->value = value;

        if (head == nullptr)
        {
            newElement->next = newElement;
            newElement->prev = newElement;
            head = newElement;
            tail = newElement;
        }
        else
        {
            newElement->next = head;
            newElement->prev = tail;
            tail->next = newElement;
            head->prev = newElement;
            tail = newElement;
        }
    }

    void insertFront(const Key& key, const Value& value)
    {
        Element* newElement = new Element;
        newElement->key = key;
        newElement->value = value;

        if (head == nullptr)
        {
            newElement->next = newElement;
            newElement->prev = newElement;
            head = newElement;
            tail = newElement;
        }
        else
        {
            newElement->next = head;
            newElement->prev = tail;
            tail->next = newElement;
            head->prev = newElement;
            head = newElement;
        }
    }
    
    void remove_all()
    {
        if (head == nullptr)
            return;

        Element* current = head;
        while (current != tail)
        {
            Element* temp = current;
            current = current->next;
            delete temp;
        }

        delete tail;
        head = nullptr;
        tail = nullptr;
    }


 // Method to check if the ring contains a key
    bool contains(const Key& key) const {
        if (head == nullptr) {
            return false;
        }

        Element* current = head;
        do {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        } while (current != head);

        return false;
    }

    // Method to update the value of a given key if it exists
    void update(const Key& key, const Value& newValue) {
        if (head == nullptr) {
            return;
        }

        Element* current = head;
        do {
            if (current->key == key) {
                current->value = newValue;
                return;
            }
            current = current->next;
        } while (current != head);
    }


void remove_current() 
{
    if (head == nullptr)
        return;
    
    // In case the head is the only element
    if (head->next == head) 
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    Element* toRemove = head;

    // Update head and tail pointers
    head = head->next;
    tail->next = head;
    head->prev = tail;

    // Remove the element
    delete toRemove;
}

    Ring& operator=(const Ring& other)
    {
        if (this == &other)
            return *this;

        remove_all();

        Element* current = other.head;
        while (current != nullptr)
        {
            insertEnd(current->key, current->value);
            current = current->next;
            if (current == other.head)
                break;
        }

        return *this;
    }


    void print()
    {
        Element* current = head;
        if (current == nullptr)
        {
            cout << "Ring is empty." << endl;
            return;
        }

        do
        {
            cout << "Key: " << current->key << ", Value: " << current->value << endl;
            current = current->next;
        } while (current != head);

        cout<<endl;

    }

    Value get_currentVal() const
    {
        if (head != nullptr)
            return head->value;

        // Return a default-constructed value if the ring is empty
        return Value();
    }

    Key get_currentKey() const
    {
        if (head != nullptr)
            return head->key;

        // Return a default-constructed value if the ring is empty
        return Key();
    }
    
    void set_current() 
{
    if (head == nullptr || head->next == nullptr)
        return;

    Element* frontElement = head;
    Element* secondElement = head->next;

    // Traverse to find the last element
    Element* lastElement = head->prev;

    // Update head and tail pointers
    head = secondElement;
    tail = lastElement;

    // Update links to move the front element to the end
    lastElement->next = frontElement;
    frontElement->prev = lastElement;
    frontElement->next = head;
    head->prev = frontElement;
}

    bool is_empty() const
{
    if (head == nullptr)
        return 1;
    else
        return 0;
}

    int count_elements() const
    {
        if (head == nullptr)
            return 0;

        int count = 0;
        Element* current = head;
        do
        {
            count++;
            current = current->next;
        } while (current != head);

        return count;
    }
        bool is_at_start() const {
        return head == nullptr || head->next == head;
    }

    // Move to the next element in the ring
    void move_next() {
        if (head != nullptr) {
            head = head->next;
        }
    }

    // Get the key of the current element
    Key get_current_key() const {
        if (head != nullptr) {
            return head->key;
        } else {
            return Key();  // Return a default-constructed Key object if the ring is empty
        }
    }

    // Get the value of the current element
    Value get_current_value() const {
        if (head != nullptr) {
            return head->value;
        } else {
            return Value();  // Return a default-constructed Value object if the ring is empty
        }
    }
};

#endif