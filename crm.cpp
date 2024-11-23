#include <bits/stdc++.h>
#include <ctime>
using namespace std;

namespace EnumUtils {
    enum class Gender {Male, Female, NA};

    string gender_to_string(Gender g) {
        switch (g) {
            case Gender::Male: return "Male";
            case Gender::Female: return "Female";
            case Gender::NA: return "Not Available";
        }
        return "Unknown";
    }

    enum class CustomerType {Prospect, New, Loyal, Recovered, Lost};

    string customer_type_to_string(CustomerType ct) {
        switch (ct) {
            case CustomerType::Prospect: return "Prospect";
            case CustomerType::New: return "New";
            case CustomerType::Loyal: return "Loyal";
            case CustomerType::Recovered: return "Recovered";
            case CustomerType::Lost: return "Lost";
        }
        return "Unknown";
    }

    enum class Status { Active, Inactive, Suspended};

    string status_to_string(Status s) {
        switch (s) {
            case Status::Active: return "Active";
            case Status::Inactive: return "Inactive";
            case Status::Suspended: return "Suspended";
        }
        return "Unknown";
    }
};

class Appointment {
    public:
    string date, time, location, consultant;
    bool confirmed_by_cust;
// Costruttore
    Appointment(string _date, string _time, string _location, string _consultant, bool _confirmed_by_cust){
            date = _date;
            time = _time;
            location = _location;
            consultant = _consultant;
            confirmed_by_cust = _confirmed_by_cust;
    }
        Appointment(){
            date = "";
            time = "";
            location = "";
            consultant = "";
            confirmed_by_cust = false;
    }
        void print_details() const {
        cout << "Data: " << date
             << ", Ora: " << time
             << ", Luogo: " << location
             << ", Consulente: " << consultant
             << ", Confermato: " << (confirmed_by_cust ? "Si" : "No") << endl;
    }
};

class Contract {
    public:
    string date, contract, inc_services, exp_date;
    bool signed_by_cust, opt_out;
// Costruttore
    Contract(string _date, string _contract, string _inc_services, string _exp_date, bool _opt_out, bool _signed_by_cust){
            date = _date;
            contract = _contract;
            inc_services = _inc_services;
            exp_date = _exp_date;
            signed_by_cust = _signed_by_cust,
            opt_out = _opt_out;
    }
        Contract(){
            date = "";
            contract = "";
            inc_services = "";
            exp_date = "";
            signed_by_cust = false;
            opt_out = false;
    }
        void print_details() const {
        cout << "Data: " << date
             << ", Contratto: " << contract
             << ", Servizi inclusi: " << inc_services
             << ", Data Scadenza: " << exp_date
             << ", Firmato: " << (signed_by_cust ? "Si" : "No")
             << ", Diritto di Recesso: " << (opt_out ? "Si" : "No") << endl;
    }
};


class Customer{
    public:
        int id;
        string name;
        string surname;
        EnumUtils::Gender gender;
        string email;
        string phone;
        string instagram;
        string linkedin;
        string job_title;
        string company;
        EnumUtils::CustomerType customer_type;
        EnumUtils::Status status;
        string birthdate;
        string address;

    static const int MAX_APPOINTMENTS = 20; // numero massimo apputnamenti
    static const int MAX_CONTRACTS = 20; // numero massimo apputnamenti
    Appointment appointments[MAX_APPOINTMENTS];
    int appointment_count;
    Contract contracts[MAX_CONTRACTS];
    int contract_count;

    // Costruttore
    Customer(int _id, string _name, string _surname, string _birthdate, string _address, EnumUtils::Gender _gender, string _email, string _phone, string _instagram, 
    string _linkedin, string _job_title, string _company, EnumUtils::CustomerType _customer_type, EnumUtils::Status _status, int _app_cnt, int _ctr_cnt){
            id = _id;
            name = _name;
            surname = _surname;
            birthdate = _birthdate;
            address = _address;
            gender = _gender;
            email = _email;
            phone = _phone;
            instagram = _instagram;
            linkedin = _linkedin;
            job_title = _job_title;
            company = _company;
            customer_type = _customer_type;
            status = _status;
            appointment_count = _app_cnt; 
            contract_count = _ctr_cnt;
    }

        Customer(){
            id = 0;
            name = "";
            surname = "";
            birthdate = "";
            address = "";
            gender = EnumUtils::Gender::NA;
            email = "";
            phone = "";
            instagram = "";
            linkedin = "";
            job_title = "";
            company = "";
            customer_type = EnumUtils::CustomerType::New;
            status = EnumUtils::Status::Inactive;
            appointment_count = 0; 
            contract_count = 0;
    }

    // Metodo per stampare i dettagli
    void print_details(){
        cout << "ID: " << id << ", Nome: " << name << " " << surname << endl
             << "Data di nascita: " << birthdate << endl
             << "Genere: " << gender_to_string(gender) << endl
             << "Email: " << email << endl
             << "Telefono: " << phone << endl
             << "Indirizzo: " << address << endl
             << "Type: " << customer_type_to_string(customer_type) << ", Status: " << status_to_string(status) << endl;
    }

    void addAppointment(const Appointment& appointment) {
        if (appointment_count < MAX_APPOINTMENTS) {
            appointments[appointment_count++] = appointment;
        } else {
            cout << "E' stato raggiunto il massimo di appuntamenti consentiti, l'appuntamento non è stato creato.\n";
        }
    }

    void showAppointments() const {
        if (appointment_count == 0) {
            cout << "Non sono stati trovati appuntamenti per il cliente " << name << " " << surname << ".\n";
        } else {
            cout << "\nAppuntamenti per il cliente " << name << " " << surname << ":\n";
            for (int i = 0; i < appointment_count; ++i) {
                cout << i + 1 << ". ";
                appointments[i].print_details();
            }
        }
    }

    void searchAppointments(const string& date) const {
        bool found = false;
        for (int i = 0; i < appointment_count; ++i) {
            if (appointments[i].date == date) {
                appointments[i].print_details();
                found = true;
            }
        }
        if (!found) {
            cout << "Non sono stati trovati appuntamenti in data " << date << ".\n";
        }
    }
    
    void addContracts(const Contract& contract) {
        if (contract_count < MAX_CONTRACTS) {
            contracts[contract_count++] = contract;
        } else {
            cout << "E' stato raggiunto il massimo di contratti consentiti, il contratto non è stato salvato.\n";
        }
    }

    void showContracts() const {
        if (contract_count == 0) {
            cout << "Non sono stati trovati contratti per il cliente " << name << " " << surname << ".\n";
        } else {
            cout << "\nContratti per il cliente " << name << " " << surname << ":\n";
            for (int i = 0; i < contract_count; ++i) {
                cout << i + 1 << ". ";
                contracts[i].print_details();
            }
        }
    }

    void searchContracts(const string& date) const {
        bool found = false;
        for (int i = 0; i < contract_count; ++i) {
            if (contracts[i].date == date) {
                contracts[i].print_details();
                found = true;
            }
        }
        if (!found) {
            cout << "Non sono stati trovati contratti con data " << date << ".\n";
        }
    }

};

class CSV_handler {
public:
    static void save_to_file(const Customer* customers, int count, const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Errore: non è stato possibile salvare il file " << filename << endl;
            return;
        }

        for (int i = 0; i < count; ++i) {
            const Customer& customer = customers[i];
            file << serialize_customer(customer) << "\n";
        }
        file.close();
        cout << "Dati salvati sul file " << filename << endl;
    }

    static void load_from_file(Customer* customers, int& count, const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Errore: non è stato possibile aprire il file " << filename << endl;
            return;
        }

        string line;
        count = 0; // Reset the count
        while (getline(file, line)) {
            customers[count++] = deserialize_customer(line);
        }
        file.close();
        cout << "Dati caricati dal file " << filename << endl;
    }

private:
    static string serialize_customer(const Customer& customer) {
        stringstream ss;
        ss << customer.id << ",\"" << customer.name << "\",\"" << customer.surname << "\",\""
           << customer.birthdate << "\",\"" << customer.address << "\",\""
           << gender_to_string(customer.gender) << "\",\"" << customer.email << "\",\""
           << customer.phone << "\",\"" << customer.instagram << "\",\"" << customer.linkedin << "\",\""
           << customer.job_title << "\",\"" << customer.company << "\",\""
           << customer_type_to_string(customer.customer_type) << "\",\"" << status_to_string(customer.status) << "\",\""
           << serialize_appointments(customer) << "\",\""
           << serialize_contracts(customer) << "\"";
        return ss.str();
    }

    static string serialize_appointments(const Customer& customer) {
        stringstream ss;
        ss << "[";
        for (int i = 0; i < customer.appointment_count; ++i) {
            const Appointment& app = customer.appointments[i];
            ss << "{"
               << "\"date\":\"" << app.date << "\","
               << "\"time\":\"" << app.time << "\","
               << "\"location\":\"" << app.location << "\","
               << "\"consultant\":\"" << app.consultant << "\","
               << "\"confirmed_by_cust\":" << (app.confirmed_by_cust ? "true" : "false")
               << "}";
            if (i < customer.appointment_count - 1) ss << ",";
        }
        ss << "]";
        return ss.str();
    }

        static string serialize_contracts(const Customer& customer) {
        stringstream ss;
        ss << "[";
        for (int i = 0; i < customer.contract_count; ++i) {
            const Contract& ctr = customer.contracts[i];
            ss << "{"
               << "\"date\":\"" << ctr.date << "\","
               << "\"contract\":\"" << ctr.contract << "\","
               << "\"inc_services\":\"" << ctr.inc_services << "\","
               << "\"exp_date\":\"" << ctr.exp_date << "\","
               << "\"signed_by_cust\":" << (ctr.signed_by_cust ? "true" : "false") << ","
               << "\"opt_out\":" << (ctr.opt_out ? "true" : "false")
               << "}";
            if (i < customer.contract_count - 1) ss << ",";
        }
        ss << "]";
        return ss.str();
    }

        // funzione per estrarre quoted fields
        static string extract_field(stringstream& ss) {
        string field;
        char ch;
        bool in_quotes = false;

        while (ss.get(ch)) {
            if (ch == '"') {
                in_quotes = !in_quotes; 
            } else if (ch == ',' && !in_quotes) {
                return field; // return campo senza quotes
            } else {
                field += ch;
            }
        }
        return field;
    }

static Customer deserialize_customer(const string& line) {
    stringstream ss(line);
    string token;

    int id;
    string name, surname, birthdate, address, genderStr, email, phone, instagram, linkedin, job_title, company, customerTypeStr, statusStr, appointmentsJson, contractsJson;
    EnumUtils::Gender gender;
    EnumUtils::CustomerType customer_type;
    EnumUtils::Status status;
    // Estrarre i valori dalla riga
    id = stoi(extract_field(ss));
    name = extract_field(ss);
    surname = extract_field(ss);
    birthdate = extract_field(ss);
    address = extract_field(ss);
    genderStr = extract_field(ss);
    gender = (genderStr == "Male") ? EnumUtils::Gender::Male : 
             (genderStr == "Female") ? EnumUtils::Gender::Female : EnumUtils::Gender::NA;
    email = extract_field(ss);
    phone = extract_field(ss);
    instagram = extract_field(ss);
    linkedin = extract_field(ss);
    job_title = extract_field(ss);
    company = extract_field(ss);
    customerTypeStr = extract_field(ss);
    customer_type = (customerTypeStr == "Prospect") ? EnumUtils::CustomerType::Prospect :
                    (customerTypeStr == "New") ? EnumUtils::CustomerType::New :
                    (customerTypeStr == "Loyal") ? EnumUtils::CustomerType::Loyal :
                    (customerTypeStr == "Recovered") ? EnumUtils::CustomerType::Recovered : EnumUtils::CustomerType::Lost;
    statusStr = extract_field(ss);
    status = (statusStr == "Active") ? EnumUtils::Status::Active :
             (statusStr == "Inactive") ? EnumUtils::Status::Inactive : EnumUtils::Status::Suspended;
    // Gli appuntamenti sono salvati come JSON nella penultima colonna
    appointmentsJson = extract_field(ss);
    // I contratti sono salvati come JSON nell'ultima colonna
    contractsJson = extract_field(ss);
    // Creare il cliente usando il costruttore
    Customer customer(id, name, surname, birthdate, address, gender, email, phone, instagram, linkedin, job_title, company, customer_type, status, 0, 0);

    // Deserializzare gli appuntamenti e aggiungerli al cliente
    deserialize_appointments(customer, appointmentsJson);

    // Deserializzare i contratti e aggiungerli al cliente
    deserialize_contracts(customer, contractsJson);

    return customer;
}


static void deserialize_appointments(Customer& customer, string& json) {
    if (json.empty() || json == "[]") return;

    stringstream ss(json.substr(1, json.size() - 2)); // Rimuove le parentesi [ ]
    string token;

    int count_app = 0; // Contatore degli appuntamenti
    while (getline(ss, token, '}')) {
        if (token.empty()) continue;

        // Rimuovere `{` e parse delle chiavi/valori
        token = token.substr(token.find('{') + 1);
        stringstream appStream(token);
        Appointment app;
        string field;

        while (getline(appStream, field, ',')) {
            size_t colonPos = field.find(':');
            string key = field.substr(0, colonPos);
            string value = field.substr(colonPos + 1);

            // Rimuovi virgolette
            key.erase(remove(key.begin(), key.end(), '\"'), key.end());
            value.erase(remove(value.begin(), value.end(), '\"'), value.end());

            if (key == "date") app.date = value;
            else if (key == "time") app.time = value;
            else if (key == "location") app.location = value;
            else if (key == "consultant") app.consultant = value;
            else if (key == "confirmed_by_cust") app.confirmed_by_cust = (value == "true");
        }

        // Aggiungere l'appuntamento al cliente
        if (customer.appointment_count < Customer::MAX_APPOINTMENTS) {
            customer.addAppointment(app);
            ++count_app;
        }
    }

    // Aggiorna il contatore degli appuntamenti del cliente
    customer.appointment_count = count_app;
}

static void deserialize_contracts(Customer& customer, const string& json) {
    if (json.empty() || json == "[]") return;
    // cin.ignore();
    stringstream ss(json.substr(1, json.size() - 2)); // Rimuove le parentesi [ ]
    string token;

    int count = 0; // Contatore 
    while (getline(ss, token, '}')) {
        if (token.empty()) continue;

        // Rimuovere `{` e parse delle chiavi/valori
        token = token.substr(token.find('{') + 1);
        stringstream appStream(token);
        Contract ctr;
        string field;

        while (getline(appStream, field, ',')) {
            size_t colonPos = field.find(':');
            string key = field.substr(0, colonPos);
            string value = field.substr(colonPos + 1);

            // Rimuovi virgolette
            key.erase(remove(key.begin(), key.end(), '\"'), key.end());
            value.erase(remove(value.begin(), value.end(), '\"'), value.end());

            if (key == "date") ctr.date = value;
            else if (key == "contract") ctr.contract = value;
            else if (key == "inc_services") ctr.inc_services = value;
            else if (key == "exp_date") ctr.exp_date = value;
            else if (key == "confirmed_by_cust") ctr.signed_by_cust = (value == "true");
            else if (key == "opt_out") ctr.opt_out = (value == "true");
        }

        // Aggiungere l'appuntamento al cliente
        if (customer.contract_count < Customer::MAX_CONTRACTS) {
            customer.addContracts(ctr);
            ++count;
        }
    }

    // Aggiorna il contatore dei contratti del cliente
    customer.contract_count = count;
}

};

namespace Helpers{

    // Funzione per leggere un intero
    int read_int(const string& prompt) {
        int value;
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            // If input is invalid, reset and prompt again
            cin.clear();               // Clear the error flag
            cin.ignore(10000000, '\n');   // Discard invalid input
            cout << "Errore: Inserire un numero valido.\n";
        }
        return value;
    }

    // Funzione per leggere una stringa
    string read_string(const string& prompt) {
        cout << prompt;
        string value;
        getline(cin, value);
        return value;
    }

    bool is_date_valid(const string& date) {
        struct tm tm_date = {};
        istringstream ss(date);
        ss >> get_time(&tm_date, "%d/%m/%Y");

        return !ss.fail();
    }

string read_date(const string& prompt, int check_older = 1) {
    while (true) {
        string date;
        cout << prompt;
        getline(cin, date);

        // Validazione del formato della data
        if (!is_date_valid(date)) {
            cout << "Errore: Formato data non valido. Usa il formato dd/mm/yyyy.\n";
            continue;
        }

        if (check_older == 1) {
            // Estrai la data dal formato stringa
            struct tm input_date = {};
            istringstream ss(date);
            ss >> get_time(&input_date, "%d/%m/%Y");

            // Ottieni la data odierna e normalizza a mezzanotte
            time_t now = time(nullptr);
            struct tm* today = localtime(&now);

            today->tm_hour = 0;
            today->tm_min = 0;
            today->tm_sec = 0;
            mktime(today);

            input_date.tm_hour = 0;
            input_date.tm_min = 0;
            input_date.tm_sec = 0;

            // Confronta la data inserita con la data odierna
            if (mktime(&input_date) >= mktime(today)) {
                return date;  // La data è valida e nel futuro o è uguale a oggi
            } else {
                cout << "Errore: La data non puo' essere nel passato.\n";
            }
        } else {
            return date;
        }
    }
}


    bool is_phone_valid(string& phone) {
        return phone.length() >= 10 && phone.find_first_not_of("0123456789") == string::npos;
    }

    bool is_email_valid(string& email) {
        return email.find('@') != string::npos && email.find('.') != string::npos;
    }

    string read_phone(const string& prompt) {
        while (true) {
            string phone;
            cout << prompt;
            getline(cin, phone);

            // Validazione del formato
            if (!is_phone_valid(phone)) {
                cout << "Errore: Formato telefono non valido. Usa solo numeri, da 6 a 11 cifre.\n";
                continue;
            }else {return phone;}

        }
    }

    string read_email(const string& prompt) {
        while (true) {
            string email;
            cout << prompt;
            getline(cin, email);

            // Validazione del formato
            if (!is_email_valid(email)) {
                cout << "Errore: Formato email non valido. La mail deve contenere una chioccola <@> e un punto <.>.\n";
                continue;
            }else {return email;}

        }
    }

    // Funzione per creare un nuovo appuntamento
    Appointment create_appointment() {
    cin.ignore();
    string date = Helpers::read_date("Inserisci la data (dd/mm/yyyy): ");
    string time = Helpers::read_string("Inserisci l'ora (hh:mm): ");
    string location = Helpers::read_string("Inserisci il luogo: ");
    string consultant = Helpers::read_string("Inserisci il consulente: ");
    bool confirmed = read_int("Appuntamento confermato dal cliente? (1 = Si, 0 = No): ");
        return Appointment(date, time, location, consultant, confirmed);
    }

    // Funzione per creare un nuovo contratto
    Contract create_contract() {
    cin.ignore();
    string date = Helpers::read_date("Inserisci la data (dd/mm/yyyy): ");
    string contract = Helpers::read_string("Inserisci il nome del contratto: ");
    string inc_services = Helpers::read_string("Inserisci una descrizione dei servizi inclusi: ");
    string exp_date = Helpers::read_date("Inserisci la data di scadenza (dd/mm/yyyy): ");
    bool confirmed = Helpers::read_int("Contratto firmato dal cliente? (1 = Si, 0 = No): ");
    bool opt_out = Helpers::read_int("Il cliente ha esercitato il diritto di recesso? (1 = Si, 0 = No): ");
        return Contract(date, contract, inc_services, exp_date, confirmed, opt_out);
    }

    Customer create_customer(int max_id) {
    cin.ignore();
    string name = Helpers::read_string("Inserisci il nome: ");
    string surname = Helpers::read_string("Inserisci il cognome: ");
    string birthdate = Helpers::read_date("Inserisci la data di nascita (dd/mm/yyyy): ", 0);
    string address = Helpers::read_string("Inserisci l'indirizzo completo (Via, civico, CAP - citta'): ");
    EnumUtils::Gender gender = static_cast<EnumUtils::Gender>(read_int("Seleziona il genere (0 = Male, 1 = Female, 2 = NA): "));
    cin.ignore();
    string email = Helpers::read_email("Inserisci l'email: ");
    string phonenumber = Helpers::read_phone("Inserisci il numero di telefono: ");
    string instagram = Helpers::read_string("Inserisci l'account Instagram (opzionale, premi Invio per saltare): ");
    string linkedin = Helpers::read_string("Inserisci l'account LinkedIn (opzionale, premi Invio per saltare): ");
    string job_title = Helpers::read_string("Inserisci la posizione lavorativa (job title): ");
    string company = Helpers::read_string("Inserisci l'azienda: ");
    EnumUtils::CustomerType customer_type = static_cast<EnumUtils::CustomerType>(read_int("Seleziona il tipo di cliente (0 = Prospect, 1 = New, 2 = Loyal, 3 = Recovered, 4 = Lost): "));
    EnumUtils::Status status = static_cast<EnumUtils::Status>(read_int("Seleziona lo stato (0 = Active, 1 = Inactive, 2 = Suspended): "));
    return Customer(max_id+1, name, surname, birthdate, address, gender, email, phonenumber, instagram, linkedin, 
                        job_title, company, customer_type, status, 0, 0);
    }
};

class CRM_process{
    private:
        Customer* customers = new Customer[100];
        int counter = 0;

        int get_max_id() {
            int max = 0;
            if (customers[0].id == 0) {
                return 0;  // if empty
            }
            for (int i = 0; i < counter; i++)
            {
                if(customers[i].id > max){
                    max = customers[i].id;
                }
            }
            return max;
        }friend int main();

        bool check_empty(){
            return customers[0].id == 0;
        }
        void empty_message(){
            cout << "Anagrafica vuota.\n";
        }


    public:
    // Aggiunta di un Cliente:
    void add_customer(Customer c){

        customers[counter] = c;
        cout << "\nCliente aggiunto correttamente: \n";
        c.print_details();
        counter++;
        }

// Visualizzazione dei Clienti:
    void show_customers() {
        if (check_empty()) {empty_message();}

        for (int i = 0; i < counter; i++) 
                {
                    customers[i].print_details(); cout <<"\n";
                }
        }


// Modifica di un Cliente: Modificare i dettagli di un cliente esistente.

void modify_customer(int cust_id) {
    bool found = false;

    if (check_empty()) {empty_message();}

    for (int i = 0; i < counter; ++i) {
        if (customers[i].id == cust_id) { // Look for a customer with the given ID
            found = true;
            int choice = Helpers::read_int("Quale attributo vuoi modificare?\n1. Nome\n2. Cognome\n3. Data di Nascita\n4. Indirizzo\n5. Genere\n6. Email\n7. Numero di Telefono\n8. Instagram\n9. LinkedIn\n10. Posizione Lavorativa\n11. Azienda\n12. Tipo di Cliente\n13. Stato\nSeleziona il numero corrispondente all'attributo: ");
            cin.ignore(); 

            switch (choice) {
                case 1: {customers[i].name = Helpers::read_string("Inserisci il nuovo nome: ");
                    break;
                }
                case 2: {customers[i].surname = Helpers::read_string("Inserisci il nuovo cognome: ");
                    break;
                }
                case 3: {customers[i].birthdate= Helpers::read_string("Inserisci la nuova data di nascita: ");
                    break;
                }
                case 4: {customers[i].address = Helpers::read_string("Inserisci il nuovo indirizzo: ");
                    break;
                }
                case 5: {customers[i].gender = static_cast<EnumUtils::Gender>(Helpers::read_int("Seleziona il genere (0 = Male, 1 = Female, 2 = NA): "));
                    break;
                }
                case 6: {customers[i].email = Helpers::read_email("Inserisci la nuova email: ");
                    break;
                }
                case 7: {customers[i].phone = Helpers::read_phone("Inserisci il nuovo numero di telefono: ");
                    break;
                }
                case 8: {customers[i].instagram = Helpers::read_string("Inserisci il nuovo account Instagram: ");
                    break;
                }
                case 9: {customers[i].linkedin = Helpers::read_string("Inserisci il nuovo account LinkedIn: ");
                    break;
                }
                case 10: {customers[i].job_title = Helpers::read_string("Inserisci la nuova posizione lavorativa: ");
                    break;
                }
                case 11: {customers[i].company = Helpers::read_string("Inserisci la nuova azienda: ");
                    break;
                }
                case 12: {customers[i].customer_type = static_cast<EnumUtils::CustomerType>(Helpers::read_int("Seleziona il tipo di cliente (0 = Prospect, 1 = New, 2 = Loyal, 3 = Recovered, 4 = Lost): "));
                    break;
                }
                case 13: {customers[i].status = static_cast<EnumUtils::Status>(Helpers::read_int("Seleziona il nuovo stato (0 = Active, 1 = Inactive, 2 = Suspended): "));
                    break;
                }
                default: {cout << "Scelta non valida.\n";
                    break;
                }
            }
            cout << "Cliente con ID " << cust_id << " modificato con successo.\n";
            return;
        }
    }

    if (!found) {
        cout << "Nessun cliente trovato con l'id: " << cust_id << endl;
    }
}


// Eliminazione di un Cliente: Rimuovere clienti dal CRM.
    void delete_customer(int cust_id) {
        bool found = false;
        if (check_empty()) {empty_message();}
        else{
            for (int i = 0; i < counter; ++i) {
                if (customers[i].id == cust_id) {
                    found = true;
                    // sposta gli elementi
                    for (int j = i; j < counter; ++j) {
                        customers[j] = customers[j + 1];
                    }
                    // riduci il conteggio di clienti
                    --counter;
                    cout << "Cliente con ID " << cust_id << " cancellato con successo.\n";
                    break;
                }
            } if (!found){cout << "Nessun cliente trovato con l'id: " << cust_id << endl;}
        }
}

// Ricerca di un Cliente: Cercare clienti per nome o cognome.

    void search_customer(string name) {
        bool found = false;
        if (check_empty()) {empty_message();}
        else{
                for (int i = 0; i < counter; i++) 
                {
                    if((name==customers[i].name) || (name==customers[i].surname)){
                    cout << "\nEcco i clienti trovati: ";
                    customers[i].print_details();
                    found = true;
                    }
                }
                if (!found) {
                cout << "Nessun cliente trovato con il nome: " << name << endl;
            }
        }
    }

    // Trova un cliente per ID
    Customer* find_customer_by_id(int id) {
        for (int i = 0; i < counter; ++i) {
            if (customers[i].id == id) {
                return &customers[i];
            }
        }
        return nullptr;
    }

    // Aggiungi un appuntamento a un cliente
    bool add_appointment(int customer_id, const Appointment& appointment) {
        Customer* customer = find_customer_by_id(customer_id);
        if (customer) {
            customer->addAppointment(appointment);
            return true;
        }
        return false;
    }

    // Mostra tutti gli appuntamenti di un cliente
    bool show_appointments(int customer_id) {
        Customer* customer = find_customer_by_id(customer_id);
        if (customer) {
            customer->showAppointments();
            return true;
        }
        return false;
    }

    // Cerca appuntamenti per data
    bool search_appointments(int customer_id, const string& date) {
        Customer* customer = find_customer_by_id(customer_id);
        if (customer) {
            customer->searchAppointments(date);
            return true;
        }
        return false;
    }

        // Aggiungi un contratto a un cliente
    bool add_contracts(int customer_id, const Contract& contract) {
        Customer* customer = find_customer_by_id(customer_id);
        if (customer) {
            customer->addContracts(contract);
            return true;
        }
        return false;
    }

    // Mostra tutti i contratti di un cliente
    bool show_contracts(int customer_id) {
        Customer* customer = find_customer_by_id(customer_id);
        if (customer) {
            customer->showContracts();
            return true;
        }
        return false;
    }

    // Cerca contratti per data
    bool search_contracts(int customer_id, const string& date) {
        Customer* customer = find_customer_by_id(customer_id);
        if (customer) {
            customer->searchContracts(date);
            return true;
        }
        return false;
    }
    
    void delete_appointments(Customer c) {
        c.appointment_count = 0;
        cout << "Appuntamenti eliminati correttamente per il cliente " << c.name << " " << c.surname << ".\n";
    }
};
        
int main(){

    // Gestisce il ciclo di interazione con l'utente tramite riga di comando.
    CRM_process crm;
    string name;
    int id, confirm;
    bool unsaved = false;
    Customer cust;
    string path = Helpers::read_string("|----------------------------------------|\n|Benvenuto nel CRM di InsuraPro Solutions|\n|Se vuoi iniziare da un file esistente,  |\n|prego inserire il percorso,             |\n|altrimenti premi invio.                 |\n|----------------------------------------|\n");
    if(path != ""){
        CSV_handler::load_from_file(crm.customers, crm.counter, path);
    }
    else {path = "./customers_interactions.csv";}

    while (true) {

    int main_choice = Helpers::read_int("\n--- Menu Principale ---\n1. Anagrafica Clienti\n2. Appuntamenti\n3. Contratti\n4. Salva\n5. Esci\nInserisci l'opzione: ");

        switch (main_choice) {
            case 1: { // Sottomenu per i clienti
            int customer_choice = Helpers::read_int("\n--- Anagrafica Clienti ---\n\n1. Aggiungi cliente\n2. Visualizza tutti i clienti\n3. Cerca cliente\n4. Rimuovi cliente\n5. Modifica cliente\n6. Torna al menu principale\nInserisci l'opzione: ");

                    switch(customer_choice) {
                    case 1:
                        printf("\nAggiungi cliente\n");
                        // Chiamare la funzione per aggiungere un cliente
                        cust = Helpers::create_customer(crm.get_max_id());
                        crm.add_customer(cust);
                        unsaved = true;
                        break;
                    case 2:
                        printf("\nVisualizza tutti i clienti: \n");
                        // Chiamare la funzione per visualizzare tutti i clienti
                        crm.show_customers();
                        break;
                    case 3:
                        printf("\nCerca cliente\n");
                        // Chiamare la funzione per cercare un cliente
                        cin.ignore();
                        name = Helpers::read_string("Inserisci il nome o cognome da cercare: ");
                        crm.search_customer(name);
                        break;
                    case 4:
                        printf("\nRimuovi cliente\n");
                        // Chiamare la funzione per rimuovere un cliente
                        while (true) {
                            id = Helpers::read_int("Inserisci l'ID del cliente da eliminare: ");                
                            crm.delete_customer(id);
                            unsaved = true;
                            break;
                            };
                        break;
                    case 5:
                        printf("\nModifica cliente\n");
                        // Chiamare la funzione per modificare un cliente
                        while (true) {
                            id = Helpers::read_int("Inserisci l'ID del cliente da modificare: ");
                                crm.modify_customer(id);
                                unsaved = true;
                                break;
                            };
                        break;
                    case 6:
                        break;
                    default:
                        printf("Scelta non valida, riprova.\n");
                }
            };
            break;
            case 2: { // Sottomenu per gli appuntamenti
                int customer_id = Helpers::read_int("\nInserisci l'ID del cliente: ");
                Customer* customer = crm.find_customer_by_id(customer_id);
                if (!customer) {
                    cout << "Cliente non trovato.\n";
                    break;
                }
                cout << "Appuntamenti del Cliente " << customer->name << " " << customer-> surname <<endl;
                int appointment_choice = Helpers::read_int("\n--- Appuntamenti ---\n1. Visualizza gli appuntamenti\n2. Cerca appuntamento per data\n3. Crea nuovo appuntamento\n4. Torna al menu principale\nInserisci l'opzione: ");
                switch (appointment_choice) {
                    case 1:
                        crm.show_appointments(customer_id);
                        break;
                    case 2: {
                        cin.ignore();
                        string date = Helpers::read_string("Inserisci la data (dd/mm/yyyy): ");
                        crm.search_appointments(customer_id, date);
                        break;
                    }
                    case 3: {
                        Appointment appointment = Helpers::create_appointment();
                        crm.add_appointment(customer_id, appointment);
                        cout << "Appuntamento creato con successo.\n";
                        unsaved = true;
                        break;
                    }
                    case 4:
                        break;
                    default:
                        cout << "Scelta non valida, riprova.\n";
                }
                break;
            }
            case 3: {// Sottomenu per i contratti
                int customer_id = Helpers::read_int("\nInserisci l'ID del cliente: ");
                Customer* customer = crm.find_customer_by_id(customer_id);

                if (!customer) {
                    cout << "Cliente non trovato.\n";
                    break;
                }
                cout << "Contratti del Cliente " << customer->name << " " << customer-> surname <<endl;
                int contract_choice = Helpers::read_int("\n--- Contratti ---\n1. Visualizza i contratti\n2. Cerca contratti per data\n3. Crea nuovo contratto\n4. Torna al menu principale\nInserisci l'opzione: ");
                switch (contract_choice) {
                    case 1:
                        crm.show_contracts(customer_id);
                        break;
                    case 2: {
                        cin.ignore();
                        string date = Helpers::read_string("Inserisci la data (dd/mm/yyyy): ");
                        crm.search_contracts(customer_id, date);
                        break;
                    }
                    case 3: {
                        Contract contract = Helpers::create_contract();
                        crm.add_contracts(customer_id, contract);
                        cout << "Contratto inserito con successo.\n";
                        unsaved = true;
                        break;
                    }
                    case 4:
                        break;
                    default:
                        cout << "Scelta non valida, riprova.\n";
                }
                break;
            }
            case 4:
                printf("\nSalva\n");
                // Chiamare la funzione per salvare a file
                CSV_handler::save_to_file(crm.customers, crm.counter, path);
                unsaved = false;
                break;
            case 5:
                printf("Esci dal programma\n");
                if(unsaved){
                    confirm = Helpers::read_int("Ci sono modifiche non salvate, vuoi uscire comunque? 1.Si 2.No: : ");
                    if(confirm == 1){
                        exit(0);
                    }
                    else{
                        continue;
                    }
                }exit(0);
            default:
                cout << "Invalid choice, try again.\n";
        }
    }
}