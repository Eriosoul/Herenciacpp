#include <iostream>
#include <vector>
using namespace std;

class Persona {
// metodo donde se iran guaradando los nombres y apellidos
private:
    std::string nombre;
    std::string apellidos;

public:
    Persona(std::string nombre, std::string apellidos) : nombre(nombre), apellidos(apellidos) {}

    ///metodo publico para acceder y modificar el atributo privado
    std::string getNombre() const { return nombre; }
    void setNombre(std::string nombre) { this->nombre = nombre; }
    std::string getApellidos() const { return apellidos; }
    void setApellidos(std::string apellidos) { this->apellidos = apellidos; }
};

class Empleado : public Persona {
private:
    // metodo donde se asignara solo la categoria en caso de que sea empleado
    std::string categoria;

public:
    Empleado(std::string nombre, std::string apellidos, std::string categoria) : Persona(nombre, apellidos), categoria(categoria) {}

    //metodo publico para acceder y modificar el atributo privado
    std::string getCategoria() const { return categoria; }
    void setCategoria(std::string categoria) { this->categoria = categoria; }
};

class Paciente : public Persona {
private:
    // metodo donde se asignara solo la categoria en caso de que sea Paciente
    std::string aseguradora;

public:
    Paciente(std::string nombre, std::string apellidos, std::string aseguradora) : Persona(nombre, apellidos), aseguradora(aseguradora) {}

    //metodo publico para acceder y modificar el atributo privado
    std::string getAseguradora() const {return aseguradora; }
    void setAseguradora(std::string aseguradora) {this->aseguradora = aseguradora; }
};

std::vector<Empleado> empleados;
void datosEmpleado(){
    string n, a, c;
    Empleado empleado(n, a, c);
    //Empleado empleado("Juan", "Pérez", "Analista");
    cout << "Nombre del empleado: ";
    cin >> n;
    empleado.setNombre(n);
    cout << "Apellido del empleado: ";
    cin >> a;
    empleado.setApellidos(a);
    cout << "Categoria del empleado: ";
    cin >> c;
    empleado.setCategoria(c); 
    // muestro los datos
    std::cout << empleado.getNombre() << " " << empleado.getApellidos() << " es un " << empleado.getCategoria() << std::endl;    
    empleados.push_back(empleado);
    cout << "\n " << endl;
}

std::vector<Paciente> pacientes;
void datosPaciente(){
    string n, a, c;
    Paciente paciente(n, a, c);
    //Empleado empleado("Juan", "Pérez", "Analista");
    cout << "Nombre del paciente: ";
    cin >> n;
    paciente.setNombre(n);
    cout << "Apellido del paciente: ";
    cin >> a;
    paciente.setApellidos(a);
    cout << "Aseguradora del paciente: ";
    cin >> c;
    paciente.setAseguradora(c); 
    std::cout << paciente.getNombre() << " " << paciente.getApellidos() << " con aseguradora " << paciente.getAseguradora() << std::endl;
    //el metodo push_back para agregar los pacientes al vector
    pacientes.push_back(paciente);
    cout << "\n " << endl;
}

void mostrarDAtos(){
    // bucle for para mostrar la informacion almaenada en los vectores 
    cout << "Los datos de nuestros Paceintes : "<< endl;
    for (int i = 0; i < pacientes.size(); i++) {
        Paciente paciente = pacientes[i];
        std::cout << paciente.getNombre() << " " << paciente.getApellidos() << " con aseguradora " << paciente.getAseguradora() << std::endl;
    }
    cout << "\n " << endl;
    cout << "Los datos de neustros Empleados: " << endl;
    for (int i = 0; i < empleados.size(); i++) {
        Empleado empleado = empleados[i];
        std::cout << empleado.getNombre() << " " << empleado.getApellidos() << " con Categoria " << empleado.getCategoria() << std::endl; 
    }
    cout << "\n " << endl;
}


int main(){
    
    int options;
    do
    {
        cout << " ¿Que tipo de registro desea almacenar ? " << endl;
        cout << " Pulse 1 para Empleado" << endl;
        cout << " Pulse 2 para Paciente" << endl;
        cout << " Pulse 3 para Mostrar datos en conjunto" << endl;
        cout << " Pulse 4 para Salir" << endl;
        cout << " ========================================= " << endl;
        cin >> options;
        switch (options)
        {
        case 1:
            datosEmpleado();
            break;
        case 2:
            datosPaciente();
            break;
        case 3:
            mostrarDAtos();
        default:
            break;
        }
    } while (options!=4);
    
}