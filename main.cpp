#include <iostream>
#include <vector>
using namespace std;


// https://www.programiz.com/online-compiler/0c2q0kStFg0pP



class Doctor {
    private:
    int id;
    string name;
    int age;
    int contact;
    string email;
    string address;
    vector<string> specialities;
    vector<string> qualification;

    public:
    static vector<Doctor*> doctors;
    static int count;
    Doctor() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Phone No.: ";
        cin >> contact;
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Address: ";
        cin >> address;
        string sp;
        cout << "Enter Speciality: ";
        cin >> sp;
        specialities.push_back(sp);
        string q;
        cout << "Enter Qualification: ";
        cin >> q;
        qualification.push_back(q);

        id = ++count;

        doctors.push_back(this);
    }

    Doctor(string n, int a, int num, string mail, string addr, string special, string qual) {
        name = n;
        age = a;
        contact = num;
        email = mail;
        address = addr;
        specialities.push_back(special);
        qualification.push_back(qual);
        id = ++count;

        doctors.push_back(this);
    }

    void display() {
        cout << "=== Doctor's Details ===\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact No.: " << contact << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
        cout << "Specialities: \n";
        for(int i=0; i<specialities.size(); i++) {
            cout << specialities[i] << endl;
        }
        cout << "Qualifications: \n";
        for(int j=0; j<qualification.size(); j++) {
            cout << qualification[j] << endl;
        }
        cout << "-----------------------------------\n";
    }
    
    void add_speciality(string sp) {
        specialities.push_back(sp);
    }

    static void all() {
        cout << "==== All Doctor's Details ====\n";
        if(doctors.size() == 0) {
            cout << "\n------------- No Doctors Found! ------------------\n\n";
        }
        for (int doctor=0; doctor<doctors.size(); doctor++) {
            doctors[doctor] -> display();
        }
    }
    
    static void searchById(int i) {
        for(int doctor=0; doctor<doctors.size(); doctor++) {
            if(doctors[doctor] -> id == i) {
                doctors[doctor] -> display();
                return;
            }
        }
        
        cout << "No Doctor Found :<";
    }
    
    static void searchByName(string n) {
        for(int doctor=0; doctor<doctors.size(); doctor++) {
            if(doctors[doctor] -> name == n) {
                doctors[doctor] -> display();
                return;
            }
        }
        
        cout << "No Doctor Found :<";
    }
    
    static void addSpeciality(int n, string sp) {
        for(int doctor=0; doctor<doctors.size(); doctor++) {
            if(doctors[doctor] -> id == n) {
                doctors[doctor] -> add_speciality(sp);
                return;
            }
        }
        
        cout << "No Doctor Found :<";
    }
};


int Doctor::count = 0;
vector<Doctor*> Doctor::doctors = {};




class Patient {
    private:
    int id;
    string name;
    int contact;
    string email;
    string address;

    public:
    static int count;
    static vector<Patient*> patients;

    Patient() {
        cout << "==== Enter Patient's Details ====\n";
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Phone No.: ";
        cin >> contact;
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Address: ";
        cin >> address;

        id = ++count;
        patients.push_back(this);
    }

    Patient(string n, int con, string mail, string addr) {
        name = n;
        email = mail;
        contact = con;
        address = addr;

        id = ++count;
        patients.push_back(this);
    }
    
    void display();

    static void all() {
        cout << "==== All Patients Details ====\n";
        if(patients.size() == 0) {
            cout << "\n------------- No Patients Found! ------------------\n\n";
        }
        for (int t=0; t<patients.size(); t++) {
            patients[t] -> display();
        }
    }

    static void searchById(int pId) {
        for(int i=0; i<patients.size(); i++) {
            if(patients[i] -> id == pId) {
                patients[i] -> display();
                return;
            }
        }
    }

    static void searchByName(string pName) {
        for(int i=0; i<patients.size(); i++) {
            if(patients[i] -> name == pName) {
                patients[i] -> display();
                return;
            }
        }
    }
};

int Patient::count = 0;
vector<Patient*> Patient::patients = {};





class Treatment {
    private:
    int treatmentId;
    int patientId;
    int doctorId;
    string diagnosis;
    string prescription;
    public:
    static int count;
    static vector<Treatment*> treatments;

    Treatment() {
        cout << "=== Enter Treament Details ===\n";
        cout << "Enter Doctor's Id: ";
        cin >> doctorId;
        cout << "Enter Patient's Id: ";
        cin >> patientId;
        
        cout << "Enter Diagnosis: ";
        cin >> diagnosis;
        cout << "Enter Prescriptions and Details: ";
        cin >> prescription;

        treatmentId = ++count;
        treatments.push_back(this);
    }

    void display_without_input() {
        cout << "=== Treatment's Details ===\n";
        cout << "Treatment's Id: " << treatmentId << endl; 
        cout << "Patient'd Id: " << patientId << endl;
        cout << "Doctors's Id: " << doctorId << endl;
        cout << "Diagnosis: " << diagnosis << endl;
        cout << "Prescriptions and Details: " << prescription << endl;
        cout << "-----------------------------------------------\n";
    }

    void display() {
        cout << "=== Treatment's Details ===\n";
        cout << "Treatment's Id: " << treatmentId << endl; 
        cout << "Patient'd Id: " << patientId << endl;
        cout << "Doctors's Id: " << doctorId << endl;
        cout << "Diagnosis: " << diagnosis << endl;
        cout << "Prescriptions and Details: " << prescription << endl;
        int choice;
        cout << "-----------------------------------------------\n";
        cout << "Enter 1, for Patient's Details, \n";
        cout << "Enter 2, for Doctor's Details, \n";
        switch(choice) {
            case 1:
                Patient::searchById(patientId);
                break;
            case 2:
                Doctor::searchById(doctorId);
                break;
            default:
                break;
        }
    }

    static void all() {
        cout << "==== All Treatment's Details ====\n";

        if(treatments.size() == 0) {
            cout << "\n------------- No Treatments Found! ------------------\n\n";
        }

        for (int t=0; t<treatments.size(); t++) {
            treatments[t] -> display_without_input();
        }
    }

    static void displayById(int tId) {
        cout << "==== Treatment Details ====\n";
        for (int t=0; t<treatments.size(); t++) {
            if(treatments[t] -> treatmentId == tId) {
                treatments[t] -> display_without_input();
                return;
            }
        }
    }

    static void displayByPatientId(int pId) {
        cout << "Patients Id: " << pId << endl;
        for(int i=0; i<treatments.size(); i++) {
            if(treatments[i] -> patientId == pId) {
                cout << "----------------------------------\n";
                cout << "Treatment's Id: " << treatments[i] -> treatmentId << endl; 
                cout << "Doctors's Id: " << treatments[i] -> doctorId << endl;
                cout << "Diagnosis: " << treatments[i] -> diagnosis << endl;
                cout << "Prescriptions and Details: " << treatments[i] -> prescription << endl;
                cout << "----------------------------------\n";
            }
        }
    }

    static void displayByDoctorId(int dId) {
        cout << "Doctor's Id: " << dId << endl;
        for(int i=0; i<treatments.size(); i++) {
            if(treatments[i] -> doctorId == dId) {
                cout << "----------------------------------\n";
                cout << "Treatment's Id: " << treatments[i] -> treatmentId << endl; 
                cout << "Patient's Id: " << treatments[i] -> patientId << endl;
                cout << "Diagnosis: " << treatments[i] -> diagnosis << endl;
                cout << "Prescriptions and Details: " << treatments[i] -> prescription << endl;
                cout << "----------------------------------\n";
            }
        }
    }
};

int Treatment::count = 0;
vector<Treatment*> Treatment::treatments = {};

void Patient::display() {
    cout << "===== Patient's Details ===== \n";
    cout << "Id: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Contact: " << contact << endl;
    cout << "Email: " << email << endl;
    cout << "Address: " << address << endl;
    cout << "Treatments: " << endl;
    Treatment::displayByPatientId(id);
    cout << "------------------------------\n";
}


class Appointment {
    private:
    int id;
    int doctorId;
    int patientId;
    string date;
    string time;

    public:
    static int count;
    static vector<Appointment*> appointments;

    Appointment() {
        cout << "==== Enter Appointment's Details ====\n";
        cout << "Enter Patient Id: ";
        cin >> patientId;
        cout << "Enter Doctor Id: ";
        cin >> doctorId;
        cout << "Enter Date: ";
        cin >> date;
        cout << "Enter Time: ";
        cin >> time;

        id = ++count;

        appointments.push_back(this);
    }

    void display_without_input() {
        cout << "=== Appointment's Detail ===\n";
        cout << "Appointment Id: " << id << endl;
        cout << "Patient's Id: " << patientId << endl;
        cout << "Doctor's Id: " << doctorId << endl;
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
        cout << "-----------------------------------------------\n";
    }

    void display() {
        cout << "=== Appointment's Detail ===\n";
        cout << "Appointment Id: " << id << endl;
        cout << "Patient's Id: " << patientId << endl;
        cout << "Doctor's Id: " << doctorId << endl;
        cout << "Date: " << date << endl;
        cout << "Time: " << time << endl;
        int choice;
        cout << "-----------------------------------------------\n";
        cout << "Enter 1, for Patient's Details, \n";
        cout << "Enter 2, for Doctor's Details, \n";
        switch(choice) {
            case 1:
                Patient::searchById(patientId);
                break;
            case 2:
                Doctor::searchById(doctorId);
                break;
            default:
                break;
        }
    }

    static void all() {
        cout << "==== All Appointments Details ====\n";
        if(appointments.size() == 0) {
            cout << "\n------------- No Appointments Found! ------------------\n\n";
        }
        for (int t=0; t<appointments.size(); t++) {
            appointments[t] -> display_without_input();
        }
    }

    static void displayById(int id) {
        for(int i=0; i<appointments.size(); i++) {
            if(appointments[i] -> id == id) {
                appointments[i] -> display_without_input();
            }
        }
    }


    static void displayByPatientId(int pId) {
        vector<Appointment*> patientAppointments = {};

        for(int i=0; i<appointments.size(); i++) {
            if(appointments[i] -> patientId == pId) {
                patientAppointments.push_back(appointments[i]);
            }
        }

        for(int j=0; j<patientAppointments.size(); j++) {
            patientAppointments[j] -> display_without_input();
        }
    }


    static void displayByDoctorId(int pId) {
        vector<Appointment*> doctorAppointments = {};

        for(int i=0; i<appointments.size(); i++) {
            if(appointments[i] -> doctorId == pId) {
                doctorAppointments.push_back(appointments[i]);
            }
        }

        for(int j=0; j<doctorAppointments.size(); j++) {
            doctorAppointments[j] -> display_without_input();
        }
    }
};

int Appointment::count = 0;
vector<Appointment*> Appointment::appointments = {};


void manageDoctors() {
    int choice;
    cout << "Enter 1, For Viewing All Doctors, \n";
    cout << "Enter 2, For Searching Doctor By Name, \n";
    cout << "Enter 3, For Searching Doctor By Id, \n";
    cout << "Enter 4, For Adding New Doctor, \n";
    cout << "Enter 5, For Adding Speciality to Doctor\n";
    cout << "Enter Choice: ";
    cin >> choice;
    string name, sp;
    int id;
    Doctor *newDoctor;

    switch(choice) {
        case 1:
            Doctor::all();
            break;
        case 2:
            cout << "Enter Name of the doctor to search: ";
            cin >> name;
            Doctor::searchByName(name);
            break;
        case 3:
            cout << "Enter Id of the doctor to search: ";
            cin >> id;
            Doctor::searchById(id);
            break;
        case 4:
            cout << "=== Enter Details Of New Doctor === \n";
            newDoctor = new Doctor();
            break;
        case 5:
            cout << "Enter Id of Doctor to add Speciality: ";
            cin >> id;
            cout << "Enter Speciality: ";
            cin >> sp;
            Doctor::addSpeciality(id, sp);
            break;
        default:
            cout << "!!! INVALID CHOICE !!!";
    }
}


void managePatients() {
    int choice;
    cout << "Enter 1, For Viewing All Patients, \n";
    cout << "Enter 2, For Searching Patient By Name, \n";
    cout << "Enter 3, For Searching Patient By Id, \n";
    cout << "Enter 4, For Adding New Patient, \n";
    cout << "Enter Choice: ";
    cin >> choice;
    string name;
    int id;
    Patient *newPatient;
    switch(choice) {
        case 1:
            Patient::all();
            break;
        case 2:
            cout << "Enter Name of the Patient to search: ";
            cin >> name;
            Patient::searchByName(name);
            break;
        case 3:
            cout << "Enter Id of the Patient to search: ";
            cin >> id;
            Patient::searchById(id);
            break;
        case 4:
            cout << "=== Enter Details Of New Patient === \n";
            newPatient = new Patient();
            break;
        default:
            cout << "!!! INVALID CHOICE !!!";
    }
}




void manageTreatments() {
    int choice;
    cout << "Enter 1, For Viewing All Treatments, \n";
    cout << "Enter 2, For Searching Treatment By Id, \n";
    cout << "Enter 3, For Searching Treatments By Patient's Id, \n";
    cout << "Enter 4, For Searching Treatments By Doctor's Id, \n";
    cout << "Enter 5, For Adding New Treatment, \n";
    cout << "Enter Choice: ";
    cin >> choice;
    int id, pId, dId;
    Treatment *newTreatment;
    switch(choice) {
        case 1:
            Treatment::all();
            break;
        case 2:
            cout << "Enter Id of Treatment to search: ";
            cin >> id;
            Treatment::displayById(id);
            break;
        case 3:
            cout << "Enter Id of the Patient to search Treatments: ";
            cin >> pId;
            Treatment::displayByPatientId(pId);
            break;
        case 4:
            cout << "Enter Id of the Doctor to search Treatments: ";
            cin >> dId;
            Treatment::displayByDoctorId(dId);
            break;
        case 5:
            cout << "=== Enter Details Of New Treatment === \n";
            newTreatment = new Treatment();
            break;
        default:
            cout << "!!! INVALID CHOICE !!!";
    }
}


void manageAppointments() {
    int choice;
    cout << "Enter 1, For Viewing All Appointments, \n";
    cout << "Enter 2, For Searching Appointments By Id, \n";
    cout << "Enter 3, For Searching Appointments By Patient's Id, \n";
    cout << "Enter 4, For Searching Appointments By Doctor's Id, \n";
    cout << "Enter 5, For Adding New Appointments, \n";
    cout << "Enter Choice: ";
    cin >> choice;
    int id, pId, dId;
    Appointment *newAppointment;
    switch(choice) {
        case 1:
            Appointment::all();
            break;
        case 2:
            cout << "Enter Id of Appointment to search: ";
            cin >> id;
            Appointment::displayById(id);
            break;
        case 3:
            cout << "Enter Id of the Patient to search Appointments: ";
            cin >> pId;
            Appointment::displayByPatientId(pId);
            break;
        case 4:
            cout << "Enter Id of the Doctor to search Appointments: ";
            cin >> dId;
            Appointment::displayByDoctorId(dId);
            break;
        case 5:
            cout << "=== Enter Details Of New Appointment === \n";
            newAppointment = new Appointment();
            break;
        default:
            cout << "!!! INVALID CHOICE !!!";
    }
}


int main() {
    cout << "===== Welcome to Aditya Hospital =====\n\n";

    // Populating Doctors
    Doctor d1("Doctor1", 45, 9999, "dr1mail", "dr1_address", "heart", "MBBS");
    d1.add_speciality("nose");
    Doctor d2("Doctor2", 25, 9889, "dr2mail", "dr2_address", "nose", "Surgeoun");
    d2.add_speciality("lungs");
    Doctor d3("Doctor3", 45, 7699, "dr2mail", "dr3_address", "brain", "MBBS");
    d3.add_speciality("neuron");

    // Populating Patients
    Patient p1("Patient1", 7777, "p1_mail", "p1_addr");
    Patient p2("Patient2", 7667, "p2_mail", "p2_addr");
    Patient p3("Patient3", 6969, "p3_mail", "p3_addr");
    
    while(1) {
        int decision;
        cout << "==== Enter Your Choice ====" << endl;
        cout << "Enter 1. For Doctors Info,\n";
        cout << "Enter 2. For Patients Info, \n";
        cout << "Enter 3. For Appointments, \n";
        cout << "Enter 4. For Treatments, \n";
        cout << "Enter 5. For Exit. \n";
        cout << "\nEnter Choice: ";
        cin >> decision;
        
        switch(decision) {
            case 1:
                cout << "--- Doctor's Menu ---\n";
                manageDoctors();
                break;
            case 2:
                cout << "--- Patient's Menu ---\n";
                managePatients();
                break;
            case 3:
                cout << "--- Appointment's Menu ---\n";
                manageAppointments();
                break;
            case 4:
                cout << "--- Treatment's Menu ---\n";
                manageTreatments();
                break;
            case 5:
                cout << "==== Thanks for trusting Aditya Hospital ====\n";
                return 1;
            default:
                cout << "!!!!! INVALID CHOICE !!!!!\n";
        }
    }
    
    return 0;
}



