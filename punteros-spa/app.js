const sections = {
  intro: `<h2>Introducción</h2>
  <p>Los punteros son variables que almacenan direcciones de memoria. En C++ se utilizan ampliamente para manipular datos y estructuras de manera eficiente.</p>`,
  simple: `<h2>Punteros Simples</h2>
  <p>Un puntero simple guarda la dirección de una variable. Para declarar un puntero se utiliza <code>*</code> antes del nombre de la variable.</p>
  <pre>// Ejemplo
int valor = 5;
int* ptr = &valor;
cout << *ptr; // muestra 5
</pre>`,
  doble: `<h2>Punteros Dobles</h2>
  <p>Un puntero doble almacena la dirección de otro puntero. Se utilizan dos asteriscos <code>**</code> en la declaración.</p>
  <pre>// Ejemplo
int valor = 10;
int* ptr = &valor;
int** dptr = &ptr;
cout << **dptr; // muestra 10
</pre>`,
  triple: `<h2>Punteros Triples</h2>
  <p>Un puntero triple almacena la dirección de un puntero doble. Es menos común pero puede aparecer en algunos algoritmos avanzados.</p>
  <pre>// Ejemplo
int valor = 20;
int* ptr = &valor;
int** dptr = &ptr;
int*** tptr = &dptr;
cout << ***tptr; // muestra 20
</pre>`
  arreglos: `<h2>Arreglos y Aritmética de Punteros</h2>
  <p>Los punteros permiten recorrer arreglos usando aritmética de punteros.</p>
  <pre>// Ejemplo
int numeros[3] = {1,2,3};
int* p = numeros;
for(int i=0; i<3; ++i){
    cout << *(p+i);
}
</pre>`,
  lista: `<h2>Lista Enlazada Simple</h2>
  <p>Cada nodo apunta al siguiente y se crea dinámicamente.</p>
  <pre>struct Nodo {
    int valor;
    Nodo* siguiente;
};

void insertar(Nodo*& cabeza, int v){
    Nodo* nuevo = new Nodo{v, cabeza};
    cabeza = nuevo;
}
</pre>`,
  dinamica: `<h2>Memoria Dinámica</h2>
  <p>Con <code>new</code> y <code>delete</code> se reserva y libera memoria manualmente.</p>
  <pre>// Ejemplo
int* datos = new int[3];
// ... usar datos
delete[] datos;</pre>`,
  estructura: `<h2>Punteros a Estructuras</h2>
  <p>Acceso a miembros con <code>-></code>.</p>
  <pre>struct Punto { int x; int y; };
Punto p{4,5};
Punto* ptr = &p;
cout << ptr->x;</pre>`,
  funcion: `<h2>Punteros a Función</h2>
  <p>Almacenan la dirección de una función.</p>
  <pre>int sumar(int a,int b){return a+b;}
int (*pf)(int,int) = &sumar;
cout << pf(2,3);</pre>`,
  memoria: `<h2>Memoria y Ensamblador</h2>
  <p>Compilando con <code>-S</code> se observan instrucciones que manejan direcciones.</p>
  <pre>// Fragmento generado
  mov rbp, rsp
  lea rax, -20[rbp]
  mov QWORD PTR -16[rbp], rax
  </pre>`,
  burbuja: `<h2>Ordenamiento Burbuja</h2>
  <p>Algoritmo simple para ordenar un arreglo mediante punteros.</p>
  <pre>void bubbleSort(int* arr, int n){
    for(int i=0;i<n-1;++i)
      for(int j=0;j<n-i-1;++j)
        if(arr[j]>arr[j+1]){
          int tmp=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=tmp;
        }
  }</pre>`,
  pila: `<h2>Pila con Lista Enlazada</h2>
  <p>Implementación de <em>push</em> y <em>pop</em> usando punteros.</p>
  <pre>struct Nodo{int v; Nodo* sig;};
void push(Nodo*& t,int v){ t=new Nodo{v,t}; }
int pop(Nodo*& t){ int v=t->v; Nodo* tmp=t; t=t->sig; delete tmp; return v; }</pre>`,
  matriz: `<h2>Matriz Dinámica</h2>
  <p>Reservar memoria para una matriz bidimensional.</p>
  <pre>int filas=2,cols=3;
int** m=new int*[filas];
for(int i=0;i<filas;++i) m[i]=new int[cols];
// ... usar m
for(int i=0;i<filas;++i) delete[] m[i];
delete[] m;</pre>`,

  seleccion: `<h2>Ordenamiento Selección</h2>
  <p>Encuentra el mínimo en cada pasada y lo coloca al inicio.</p>
  <pre>void seleccion(int* a,int n){
    for(int i=0;i<n-1;++i){
      int m=i;
      for(int j=i+1;j<n;++j)
        if(a[j]<a[m]) m=j;
      int t=a[i]; a[i]=a[m]; a[m]=t;
    }
  }</pre>`,

  insercion: `<h2>Ordenamiento Inserción</h2>
  <p>Va insertando cada elemento en su posición correcta.</p>
  <pre>void insercion(int* a,int n){
    for(int i=1;i<n;++i){
      int k=a[i],j=i-1;
      while(j>=0 && a[j]>k){
        a[j+1]=a[j]; --j;
      }
      a[j+1]=k;
    }
  }</pre>`,

  merge: `<h2>Merge Sort</h2>
  <p>Divide y conquista; mezcla subarreglos ordenados.</p>
  <pre>void mergeSort(int* a,int l,int r){
    if(l<r){
      int m=l+(r-l)/2;
      mergeSort(a,l,m);
      mergeSort(a,m+1,r);
      /* fusion */
    }
  }</pre>`,

  rapido: `<h2>Quick Sort</h2>
  <p>Elige un pivote y ordena alrededor de él recursivamente.</p>
  <pre>void quickSort(int* a,int l,int r){
    if(l<r){
      int p=partition(a,l,r);
      quickSort(a,l,p-1);
      quickSort(a,p+1,r);
    }
  }</pre>`,

  heap: `<h2>Heap Sort</h2>
  <p>Convierte el arreglo en un heap y extrae el máximo repetidamente.</p>
  <pre>void heapSort(int* a,int n){
    for(int i=n/2-1;i>=0;--i) heapify(a,n,i);
    for(int i=n-1;i>0;--i){
      swap(a[0],a[i]);
      heapify(a,i,0);
    }
  }</pre>`,

  binaria: `<h2>Búsqueda Binaria</h2>
  <p>Busca un elemento dividiendo el arreglo ordenado.</p>
  <pre>int busqueda(int* a,int n,int x){
    int l=0,r=n-1;
    while(l<=r){
      int m=l+(r-l)/2;
      if(a[m]==x) return m;
      if(a[m]<x) l=m+1; else r=m-1;
    }
    return -1;
  }</pre>`,

  lineal: `<h2>Búsqueda Lineal</h2>
  <p>Recorre secuencialmente hasta encontrar el elemento.</p>
  <pre>int lineal(int* a,int n,int x){
    for(int i=0;i<n;++i)
      if(a[i]==x) return i;
    return -1;
  }</pre>`,

  factorial: `<h2>Factorial Recursivo</h2>
  <p>Ejemplo de recursión clásica.</p>
  <pre>long fact(int n){
    if(n<=1) return 1;
    return n*fact(n-1);
  }</pre>`,

  fibonacci: `<h2>Fibonacci</h2>
  <p>Secuencia que suma los dos anteriores.</p>
  <pre>int fib(int n){
    int a=0,b=1,c;
    for(int i=2;i<=n;++i){
      c=a+b; a=b; b=c;
    }
    return b;
  }</pre>`,

  bfs: `<h2>BFS</h2>
  <p>Recorrido en anchura de un grafo usando cola.</p>
  <pre>void bfs(vector<vector<int>> g,int s){
    queue<int> q; vector<bool> v(g.size(),false);
    v[s]=true; q.push(s);
    while(!q.empty()){int u=q.front();q.pop();
      for(int w:g[u]) if(!v[w]){v[w]=true;q.push(w);} }
  }</pre>`,

  cola: `<h2>Cola</h2>
  <p>Estructura FIFO implementada con punteros.</p>
  <pre>struct Nodo{int v; Nodo* sig;};
struct Cola{Nodo* f=nullptr,*r=nullptr;
  void encolar(int x){Nodo*n=new Nodo{x,nullptr};
    if(!f) f=r=n; else{r->sig=n; r=n;}}
  int desencolar(){int x=f->v; Nodo*t=f; f=f->sig;
    if(!f) r=nullptr; delete t; return x;}}
  </pre>`,

  listaDoble: `<h2>Lista Doble</h2>
  <p>Nodos que apuntan al siguiente y anterior.</p>
  <pre>struct N{int v; N* sig; N* ant;};
void insertar(N*& h,int v){N*n=new N{v,h,nullptr}; if(h) h->ant=n; h=n;}</pre>`,

  arbol: `<h2>Árbol Binario</h2>
  <p>Cada nodo tiene dos hijos como máximo.</p>
  <pre>struct Nodo{int v; Nodo* izq; Nodo* der;};
Nodo* crear(int v){return new Nodo{v,nullptr,nullptr};}</pre>`,

  bst: `<h2>Árbol BST</h2>
  <p>Mantiene los elementos ordenados para búsquedas rápidas.</p>
  <pre>void insertar(Node*& r,int v){if(!r)r=new Node{v,0,0};
else if(v<r->val) insertar(r->left,v); else insertar(r->right,v);}</pre>`,

  grafo: `<h2>Grafo</h2>
  <p>Representado con listas de adyacencia.</p>
  <pre>vector<vector<int>> g={{1,2},{2},{0},{}};</pre>`,

  hash: `<h2>Tabla Hash</h2>
  <p>Distribuye claves por una función hash.</p>
  <pre>vector<vector<int>> t(5);
int h(int x){return x%t.size();}
void insertar(int x){t[h(x)].push_back(x);}</pre>`,

  heapDS: `<h2>Heap</h2>
  <p>Estructura de prioridad basada en un arreglo.</p>
  <pre>vector<int> a;
void push(int v){a.push_back(v);/*ajustar*/}
int pop(){/*extraer max*/}</pre>`,

};

const content = document.getElementById('content');

document.querySelectorAll('nav button').forEach(btn => {
  btn.addEventListener('click', () => {
    const id = btn.getAttribute('data-section');
    content.innerHTML = sections[id];
  });
});

// Mostrar introducción por defecto
content.innerHTML = sections.intro;
