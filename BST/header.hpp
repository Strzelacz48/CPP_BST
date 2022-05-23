<typename T>
    class bst<T>
    {
    public://kostruktory
        bst<T>();
        // destruktor
        ~bst<T>();
        bst<T>(const bst<T> &bst); // konstruktor kopiujący
        bst<T>(initializer_list<T>)//kostruktor z listą inicjalizującą
        bst<T>(bst<T> &&tb); // konstruktor przenoszący
        bst<T>& operator = (const bst<T> &bst); // przypisanie kopiujące
        bst<T>& operator = (bst<T> &&bst); // przypisanie przenoszące
    public://zmienne
        node<T> start;
    public://funkcje
        void add(T key);
        void rm(T key);
        bool find(T key);
    private:
    <typename T>
        class node<T>
        {
        public:
            node<T>(T val);
            node<T>(T val,node l,node r);
            node parent;
            node *left;
            T key;
            node *right;
            bool isleaf;
        public:
            T maksimum(const T &a, const T &b);
            node *add(T key);
            void rm(T key);
            bool find(T key);
            void destpom(node *a);
        };
    } ;

