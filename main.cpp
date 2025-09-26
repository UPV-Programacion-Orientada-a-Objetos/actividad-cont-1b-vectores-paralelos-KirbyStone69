#include <iostream>
#include <iomanip>
#include <fstream>
#include <string> 

const int max_num = 100;
int n_load=0;

int codigo_producto[max_num]={}; //Código
std::string nombre_producto[max_num]={}; //Nombre
int stock_producto[max_num]={}; //Cantidad
float precio_producto[max_num]={}; //Precio
std::string almacen_producto[max_num]={}; // Ubicación

int guardar();
void agregar();
int stringToInt( std::string cadena );
int inicializador();
int verifica_numericos(std::string mensaje);
void buscar_mayor_precio();
void reporte();
void consulta_producto();
void modificar_stock();


int main() {
    std::cout << "---- Bienvenido al sistema de Inventario de El Martillo ---"<<std::endl;
    std::cout << "Cargando inventario desde 'inventario.txt'..."<<std::endl;
    n_load = inicializador();
    if (n_load == -1){
        std::cout << "No se encontro el archivo, consulte con un experto en sistemas c++ hechos en menos de 2 horas"<<std::endl;
        return 0;
    }
    
    std::cout << "se cargaron :" <<n_load << " Productos"<<std::endl;
    while (true){     
        std::cout<<"--- Menú principal ---"<< std::endl<< std::endl; 
        
        std::cout << "Seleccione una opción:"<<std::endl;
        std::cout << "1. Consultar un producto"<<std::endl;
        std::cout << "2. Actualizar inventariado por ubicación"<<std::endl;
        std::cout << "3. Registrar nuevo producto"<<std::endl;
        
        std::cout << "4. Generar reporte de bajo stock"<<std::endl;
        std::cout << "5. Encontrar el producto más barato"<<std::endl;
        std::cout << "6. Guardar y Salir"<<std::endl<<std::endl;
        int opcion=0;

        opcion = verifica_numericos("Opción seleccionada");
        if(opcion == -1){continue;}
        if (!(opcion >= 1 && opcion<=6)){
            std::cout << "Esa opcion no existe"<<std::endl<<std::endl;
            continue;
        }

        switch (opcion){
        case 1:
            consulta_producto();
            break;
        case 2:
            modificar_stock();
            break;
        case 3:
            agregar();
            break;
        case 4:
            reporte();
            break;
        case 5:
            buscar_mayor_precio();
            break;
        case 6:
        if(!(guardar() == -1)){
            std::cout<<"⣿⣿⣿⣿⣿⢻⣿⣿⣿⣿⣿⣿⣆⠻⡫⣢⠿⣿⣿⣿⣿⣿⣿⣿⣷⣜⢻⣿\n⣿⣿⡏⣿⣿⣨⣝⠿⣿⣿⣿⣿⣿⢕⠸⣛⣩⣥⣄⣩⢝⣛⡿⠿⣿⣿⣆⢝\n⣿⣿⢡⣸⣿⣏⣿⣿⣶⣯⣙⠫⢺⣿⣷⡈⣿⣿⣿⣿⡿⠿⢿⣟⣒⣋⣙⠊\n⣿⡏⡿⣛⣍⢿⣮⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⢱⣾⣿⣿⣿⣝⡮⡻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠛⣋⣻⣿⣿⣿⣿\n⢿⢸⣿⣿⣿⣿⣿⣿⣷⣽⣿⣿⣿⣿⣿⣿⣿⡕⣡⣴⣶⣿⣿⣿⡟⣿⣿⣿\n⣦⡸⣿⣿⣿⣿⣿⣿⡛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⣿⣿⣿\n⢛⠷⡹⣿⠋⣉⣠⣤⣶⣶⣿⣿⣿⣿⣿⣿⡿⠿⢿⣿⣿⣿⣿⣿⣷⢹⣿⣿\n⣷⡝⣿⡞⣿⣿⣿⣿⣿⣿⣿⣿⡟⠋⠁⣠⣤⣤⣦⣽⣿⣿⣿⡿⠋⠘⣿⣿\n⣿⣿⡹⣿⡼⣿⣿⣿⣿⣿⣿⣿⣧⡰⣿⣿⣿⣿⣿⣹⡿⠟⠉⡀⠄⠄⢿⣿\n⣿⣿⣿⣽⣿⣼⣛⠿⠿⣿⣿⣿⣿⣿⣯⣿⠿⢟⣻⡽⢚⣤⡞⠄⠄⠄⢸⣿\n";
            std::cout<<"see you the next time, onichan\n";
            return 0;
            }
            break;
        default:
            break;
        }
    }
    return 0;
}

void consulta_producto(){
    int codigo_consultado=0;
    int index_encontrado=-1; //inicializo en -1 por si hay algun error
    codigo_consultado=verifica_numericos("Ingrese el código del producto a consultar");
    for (int i = 0; i < n_load; i++){
        //busca el codigo consultado si lo encuentra guarda el index
        if (codigo_producto[i] == codigo_consultado){
            index_encontrado = i;
            //se cierra el ciclo por que ya para que voy a andar buscando
            break;
        }
    }
    //lo encuentre o no lo en
    if (index_encontrado != -1){
        std::cout<<"Información del Producto :"<<std::endl;
        std::cout<<"Código: "<< codigo_producto[index_encontrado] <<std::endl;
        std::cout<<"Nombre: "<< nombre_producto[index_encontrado] <<std::endl;
        std::cout<<"Cantidad en stock: "<< stock_producto[index_encontrado] <<std::endl;
        std::cout<<"Precio unitario: $"<< precio_producto[index_encontrado] <<std::endl;
        std::cout<<"Ubicacion: "<< almacen_producto[index_encontrado] <<std::endl<<std::endl;

    }else{std::cout<<"Código de producto invalido"<<std::endl<<std::endl;}
    
}

int verifica_numericos(std::string mensaje){
        int valor = 0;
        std::cout << mensaje<<": ";
        std::cin >> valor;
        std::cout<<std::endl;
        if(!(std::cin.good())){ // aqui valida si no hubo error al ingresar un dato
            //cin.god si da tru es por que no hubo error, aqui verifico que sea diferente de tru
            std::cin.clear();//elimina el estado del cin.good ya no es de error
            /*aqui aviendo un ciclo que me este sacando los datotes
            mientras sean diferentes al salto de linea o enter como tengo entendido*/
            while(std::cin.get() != '\n'){}//no hace nada el ciclo pero saca todo del cache / buffer del cin
            
            std::cout << "caracter no valido:Se Espera un numero"<<std::endl<<std::endl;
            //como se ingreso un dato erroneo se devuelve un dato que no acepten los otros parametros
            return -1;
        }
    return valor;
}

void buscar_mayor_precio(){
    int valor=5000, centinela=0;

    for (int i = 0; i < n_load; i++){
        if (precio_producto[i]<valor){
            valor = precio_producto[i];
            centinela = i;
        }
    }
    std::cout<<"El producto más caro es: "<< nombre_producto[centinela]<<" con un precio de $"<<precio_producto[centinela]<<std::endl;
}

void reporte(){
    std::cout<< "--- Reporte de Inventario bajo ---"<< std::endl;
    std::cout<< std::left <<std::setw(9)<< "Codigo"<<"|"
                            << std::setw(25)<<"Nombre"<<"|"
                            << std::setw(9)<<"Stock"<<"|"
                            << std::setw(9)<<"Precio"<<"|"
                            << std::setw(9)<<"Ubicacion"<< std::endl;
    std::cout<< "-------------------------------------------------------"<< std::endl;
    //aqui use setw de la libreria iomanip para que se vea mas bonito
    for (int i = 0; i < n_load; i++){
        if(stock_producto[i] <= 10){
            std::cout<< std::left <<std::setw(9)<< codigo_producto[i]<<"|"
            << std::setw(25)<<nombre_producto[i]<<"|"
            << std::setw(9)<<stock_producto[i]<<"|"
            << std::setw(9)<<precio_producto[i]<<"|"
            << std::setw(9)<<almacen_producto[i]<< std::endl;
        }
    }
    std::cout<<std::endl;
}

void modificar_stock(){
    std::string ubi;
    int in_en=-1; //inicializo en -1 por si hay algun error
    std::cout << "Ingrese la ubicacion a modificar:";
    std::cin >> ubi;
    for (int i = 0; i < n_load; i++){
        //busca el codigo consultado si lo encuentra guarda el index
        if (almacen_producto[i] == ubi){
            in_en = i;
            //se cierra el ciclo por que ya para que voy a andar buscando
            break;
        }
    }

    if (in_en != -1){
        std::cout<<"stock actual de "<< nombre_producto[in_en]<<" es de " <<stock_producto[in_en]<<std::endl;

        int suma=0;
        int nuevo_stock;
        suma = verifica_numericos("Ingrese la cantidad a sumar");
        if (suma == 0){
            std::cout<<"No puedes sumar 0 al stock"<<std::endl;
        }else if ((stock_producto[in_en]+suma)< 0){
            std::cout<<"Cantidad no valida para ingresar"<<std::endl;
        }else{
            stock_producto[in_en] += suma;
        }
            std::cout<<"stock actual de "<< nombre_producto[in_en]<<" es de " <<stock_producto[in_en]<<std::endl;
    }else{std::cout<<"cantidad de a sumar no valida"<<std::endl<<std::endl;}
    
}

int stringToInt( std::string cadena )
{
    int result = 0;

        for ( int i = 0; i < cadena.size(); i++ ){
        int digit = cadena[i] - '0';
      result = 10 * result + digit;
    }

    return result;
}

int inicializador(){
    int index_dato = 0;
    std::string dato = "";
    char c;
    std::fstream invetario("data/inventario.txt");

    if(!invetario.is_open()){
        std::cout<< "archvo no encontrado"<< std::endl;
    }else{
        getline(invetario, dato);
        dato = "";
        int i=0;
        while (invetario.get(c)){
            if(c == ',' || c== '\n'){
                switch (index_dato){
                case 0:
                        codigo_producto[i] = stringToInt(dato);
                    break;
                case 1:
                        nombre_producto[i] = dato;
                    break;
                case 2:
                        stock_producto[i] = stringToInt(dato);
                    break;
                case 3:
                        precio_producto[i] = std::stof (dato);
                    break;
                case 4:
                        almacen_producto[i] = dato;
                    break;
                default:
                    break;
                }
                index_dato +=1;
                dato = "";
                if (c == '\n'){
                    index_dato = 0;
                    i+=1;
                }                
            }else{
                dato += c;
            }
        }
        almacen_producto[i] = dato;
        std::cout<<dato<<std::endl;
        return i+1;
    }
    return -1;
}

int guardar(){
    std::ofstream guardar("data/inventario.txt");
    std::string todo = "Código,Nombre,Cantidad,Precio,Ubicación\n";
    if(guardar.is_open()){
        for (int i = 0; i < n_load; i++){
            std::stringstream ss;
            ss <<std::fixed << std::setprecision(2) << precio_producto[i];
            std::string precio_formateado = ss.str();
            todo += std::to_string(codigo_producto[i])+","+nombre_producto[i]+
            ","+std::to_string(stock_producto[i])+","+precio_formateado+
            ","+almacen_producto[i];
            if (!((i+1) >= n_load)){
                todo +='\n';
            }
        }
        guardar<<todo;
        guardar.close();
        return 1;
    }else{
        std::cout << "No se pudo guardar"<<std::endl;
        return -1;
    }
}

void agregar(){
    int etapa=0;
    int code=0;
    std::string nombre="";
    int stock=0;
    float precio=0.00;
    std::string almacen="",ss;
    bool bandera=false;
    bool bandera_red=false;

while (!bandera){
    switch (etapa){
        case 0:
            code = verifica_numericos("Ingrese el codigo");
            if (code >= 1){
                for (int i = 0; i < n_load; i++){
                    if (code == codigo_producto[i]){
                        std::cout << "Este codigo ya exite"<<std::endl;
                        break;
                    }
                }
            }else{
                std::cout<< "No se puede añadir datos negativos"<<std::endl;
                continue;
            }
            etapa++;
        break;
        case 1:
            std::cin.ignore();
            std::cout<<"Ingrese el nombre del producto:";
            std::getline(std::cin,nombre);
            etapa++;
        break;
        case 2:
            stock = verifica_numericos("Ingrese la cantidad en stock");
            if (stock >= 1){
            }else{
                std::cout<< "No se puede añadir cantidad negativa"<<std::endl;
                continue;
            }
            etapa++;
        break;
        case 3:
            std::cout<<"Ingrese el precio del producto:";
            std::cin>>ss;
            try {
                precio = std::stof(ss);
                if (precio >= 0.0f) {
                    etapa++;
                } else {
                    std::cout << "No se puede añadir precio negativo" << std::endl;
                }
            }catch (const std::invalid_argument& e){
                std::cout << "no se permiten caracteres" << std::endl;
            }catch (const std::out_of_range& e){
                std::cout << "Numero muy grande para usar" << std::endl;
            }
        break;
        case 4:
            std::cout<<"Ingrese la ubicacion del producto:";
            std::cin>>almacen;
                bandera_red=false;
                for (int i = 0; i < n_load; i++){
                    if (almacen == almacen_producto[i]){
                        std::cout << "Este codigo ya exite"<<std::endl;
                        bandera_red = true;
                        break;
                    }
                }
            if (!bandera_red){
                bandera = true;
            }            
            break;
        default:
        break;
        }
        std::cout<<etapa<<std::endl;
        std::cout<<code<<std::endl;
        std::cout<<nombre<<std::endl;
        std::cout<<stock<<std::endl;
        std::cout<<precio<<std::endl;
        std::cout<<almacen<<std::endl;
    }
    codigo_producto[n_load] = code;
    nombre_producto[n_load] = nombre;
    stock_producto[n_load] = stock;
    precio_producto[n_load] = precio;
    almacen_producto[n_load] = almacen;
    n_load+=1;
}