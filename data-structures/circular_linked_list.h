#include <cinttypes>

namespace DataStructures
{
    template <typename T>
    class CircularLinkedList
    {
        using ValueType = T;
        using SizeType = uint64_t;
        using IndexType = uint64_t;

        public:
            struct Node
            {
                ValueType value;
                Node *prev = nullptr;
                Node *next = nullptr;

                Node (const ValueType& val)
                {
                    this->value = val;
                }

                inline Node* operator++ (int)
                {
                    return this->next;
                }
                
                inline Node* operator-- (int)
                {
                    return this->prev;
                }

                inline bool operator== (Node* node)
                {
                    return this == node;
                }

                inline bool operator!= (Node* node)
                {
                    return this != node;
                }
            };
        
        private:
            Node *head = nullptr;
            Node *tail = nullptr;
            SizeType _size = 0;

        public:
            ~CircularLinkedList ()
            {
                // TODO - clean up memory
            }

        public:
            inline SizeType size() const noexcept
            {
                return this->_size;
            }
            inline bool empty() const noexcept
            {
                return this->_size == 0;
            }

        public:
            void push_back (const ValueType& val)
            {
                Node *new_node = new Node(val);
                this->_size++;
                if (this->head == nullptr)
                {
                    this->head = new_node;
                    this->tail = new_node;
                }
                else
                {
                    this->tail->next = new_node;
                    new_node->prev = this->tail;
                    this->tail = new_node;
                }
            }
            ValueType& at (IndexType index)
            {
                IndexType last_index = this->size() - 1;
                
                if (index > last_index)
                    throw std::out_of_range("Index out of range");

                Node *node;

                if (index < (last_index / 2))
                {
                    node = this->head;
                    for (IndexType i = 0; i < index; i++)
                        node = node->next;
                }
                else
                {
                    node = this->tail;
                    for (IndexType i = last_index; i > index; i--)
                        node = node->prev;
                }
                return node->value;
            }
    };
};
