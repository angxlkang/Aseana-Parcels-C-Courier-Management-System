#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <regex>

using namespace std;

class Person{
protected:
    string firstName;
    string lastName;
    string fullName;
    string company;
    string address;
    string email;
    string country;
    string state;
    string type;
    string postcode;
    string contact;
    void generateFullName(){
        fullName=firstName+" "+lastName;
    }
    bool isValidEmail(string e){
        return e.find('@')!=string::npos && e.find('.')!=string::npos;
    }

public:
    Person()=default;
    Person(string fn,string ln,string com,string add,string c,string p,string e,string t,string ctry,string s){
        firstName=fn;
        lastName=ln;
        generateFullName();
        company=com;
        address=add;
        contact=c;
        postcode=p;
        email=e;
        type=t;
        country=ctry;
        state=s;
    }
    void setFirstName(string fn){
        firstName=fn;
        generateFullName();
    }
    void setLastName(string ln){
        lastName=ln;
        generateFullName();
    }
    void setAddress(string add){
        address=add;
    }
    void setCompany(string com){
        company=com;
    }
    void setContact(string c){
        contact=c;
    }
    void setPostcode(string p){
        postcode=p;
    }
    void setEmail(string e){
        if(isValidEmail(e))
            email=e;
        else
            throw invalid_argument("Invalid email address.");
    }
    void setState(string s){
        state=s;
    }
    void setType(string t){
        type=t;
    }
    void setCountry(string ctry){
        country=ctry;
    }
    string getName(){
        return fullName;
    }
    string getAddress(){
        return address;
    }
    string getCompany(){
        return company;
    }
    string getContact(){
        return contact;
    }
    string getPostcode(){
        return postcode;
    }
    string getEmail(){
        return email;
    }
    string getState(){
        return state;
    }
    string getType(){
        return type;
    }
    string getCountry(){
        return country;
    }

    virtual void Display() const{
        cout<<"Name: "<<getName()<<endl;
        cout<<"Type: "<<getType()<<endl;
        cout<<"Company: "<<getCompany()<<endl;
        cout<<"Country: "<<getCountry()<<endl;
        cout<<"Address: "<<getAddress()<<endl;
        cout<<"Postcode: "<<getPostcode()<<endl;
        cout<<"State: "<<getState()<<endl;
        cout<<"Email: "<<getEmail()<<endl;
        cout<<"Contact Number: "<<getContact()<<endl<<endl;
    }
};

class Sender:public Person{
public:
    Sender(string fn,string ln,string com,string add,string c,string p,string e,string t,string ctry,string s):Person(fn, ln, com, add, c, p, e, t, ctry, s){}
    void Display() const override{
        cout<<"Sender Details "<<endl;
        Person::Display();
    }
};

class Receiver:public Person{
public:
    Receiver(string fn,string ln,string com,string add,string c,string p,string e,string t,string ctry,string s):Person(fn, ln, com, add, c, p, e, t, ctry, s){}
    void Display() const override{
        cout<<"Receiver Details "<<endl;
        Person::Display();
    }
};

class Shipment{
private:
    Sender sender;
    Receiver receiver;
    string origin;
    string destination;
    double weight;
    double length;
    double width;
    double height;
    string dimension;
    int shipDay;
    int shipMonth;
    int shipYear;
    string shipDate;
    string deliDate;
    string pickupDate;

    void generateDimension(){
        dimension=to_string(width)+"*"+to_string(length)+"*"+to_string(height);
    }
    void generateShipDate(){
        shipDate=(shipDay<10?"0":"")+to_string(shipDay)+"-"+(shipMonth<10?"0":"")+to_string(shipMonth)+"-"+to_string(shipYear);
    }

    void generatePickupDate(){
        Date date = generateDate(shipDay, shipMonth, shipYear, 1);
        pickupDate=(date.day<10?"0":"")+to_string(date.day)+"-"+(date.month<10?"0":"")+to_string(date.month)+"-"+to_string(date.year);
    }

    void generateDeliDate(){
        Date date = generateDate(shipDay, shipMonth, shipYear, 1);
        Date date2 = generateDate(date.day, date.month, date.year, 3);
        deliDate=(date2.day<10?"0":"")+to_string(date2.day)+"-"+(date2.month<10?"0":"")+to_string(date2.month)+"-"+to_string(date2.year);
    }

public:
    Shipment(Sender s,Receiver r,string o,string des, double w, double l,double wid, double h,int d,int m, int y){
        sender=s;
        receiver=r;
        origin=o;
        destination=des;
        weight=w;
        length=l;
        width=wid;
        height=h;
        shipDay=d;
        shipMonth=m;
        shipYear=y;
        generateDimension();
        generateShipDate();
        generatePickupDate();
        generateDeliDate();
    }
    void setOrigin(string o){
        origin=o;
    }
    void setDestination(string des){
        destination=des;
    }
    void setWeight(double w){
        weight=w;
    }
    void setLength(double l){
        length=l;
    }
    void setWidth(double wid){
        width=wid;
    }
    void setHeight(double h){
        height=h;
    }
    void setShipDay (int d){
        shipDay=d;
    }
    void setShipMonth(int m){
        shipMonth=m;
    }
    void setShipYear(int y){
        shipYear=y;
    }
    string getOrigin(){
        return origin;
    }
    string getDestination(){
        return destination;
    }
    double getWeight(){
        return weight;
    }
    double getLength(){
        return length;
    }
    double getWidth(){
        return width;
    }
    double getHeight(){
        return height;
    }
    string getDimension(){
        return dimension;
    }
    string getShipDate(){
        return shipDate;
    }
    string getDeliveryDate(){
        return deliDate;
    }
    string getPickupDate(){
        return pickupDate;
    }

    // display sender+receiver+shipment details
    void displayDetails(){
        sender.Display();
        receiver.Display();
        cout<<"Shipment Details"<<endl;
        cout<<"Origin: "<<getOrigin()<<endl;
        cout<<"Destination: "<<getDestination()<<endl;
        cout<<"Weight: "<<getWeight()<<" kg"<<endl;
        cout<<"Dimension: "<<getDimension()<<" cm"<<endl;
        cout<<"Shipment Date : "<<getShipDate()<<endl;
        cout<<"Pick Up Date  : "<<getPickupDate()<<endl;
        cout<<"Delivery Date : "<<getDeliveryDate()<<endl<<endl;
    }
};

struct Date {
    int day;
    int month;
    int year;
};

Date generateDate(int day, int month, int year, int skip) {
        int daysInMonth;
        int newMonth=month;
        int newYear=year;
        int newDay=day+skip;

        if(month==2)
            daysInMonth=(checkYear(year))?29:28;
        else if(month==4||month==6||month==9||month==11)
            daysInMonth=30;
        else
            daysInMonth=31;

        if(newDay>daysInMonth){
            newDay-=daysInMonth;
            newMonth++;
            if(newMonth>12){
                newMonth=1;
                newYear++;
            }
        }
        return {newDay, newMonth, newYear};
}

bool checkYear(int y){
        if(y%400==0 || (y%100!=0 && y%4==0))
            return true;
        else return false;
}

class ShipmentDetail{
private:
    string shippingType;
    string purpose;
    int choice1;
    int choice2;
    string description;
    int quantity;
    int unit;
    double weightPerItem;
    double value;
    string p_origin;
    long invoice_num;

    void genType(){
        switch(choice) {
            case 1: shippingType = "Documents";
                    break;
            case 2: shippingType = "Packages";
                    break;
            case 3: shippingType = "Pallets";
                    break;
            case 4: shippingType = "Cargo";
                    break;
            case 5: shippingType = "Containers";
                    break;
            default: cout<<"Invalid Choice"<<endl;
                    break;
        }
    }
    void genPurpose(){
        switch(choice2){
            case 1: purpose="Gift";
                    break;
            case 2: purpose="Commercial";
                    break;
            case 3: purpose="Personal, Not for Resale";
                    break;
            case 4: purpose="Sample";
                    break;
            case 5: purpose="Return";
                    break;
            case 6: purpose="Temporary Export";
                    break;
            default: cout<<"Invalid Choice";
                    break;
        }
    }
public:
    ShipmentDetail(int c1,int c2,string desc,int qty,int unit,double w,double v,string org,long num){
        choice1=c1;
        choice2=c2;
        genType();
        genPurpose();
        description=desc;
        quantity=qty;
        unit=unit;
        value=v;
        weightPerItem=w;
        p_origin=org;
        invoice_num=num;
    }
    void setDesc(string d){
        description=d;
    }
    void setUnit(int u) {
        unit = u;
    }
    void setWeightPerItem(double w) {
        weightPerItem = w;
    }
    void setQty(int q){
        quantity=qty;
    }
    void setValue(double v){
        value=v;
    }
    void setOrigin(string org){
        p_origin=org;
    }
    void setInvNum(long num){
        invoice_num=num;
    }

    void setC1(int a){
        choice1=a;
    }
    void setC2(int b){
        choice2=b;
    }
    string getDesc(){
        return description;
    }
    int getQuantity(){
        return quantity;
    }
    double getValue(){
        return value;
    }
    string getOrigin(){
        return origin;
    }
    string getShippingType(){
        return shippingType;
    }
    string getPurpose(){
        return purpose;
    }
    int getUnit(){
        return unit;
    }
    double getWeightPerItem(){
        return weightPerItem;
    }
    long getInvNum(){
        return invoice_num;
    }
    void display() const {
    cout << "Shipment Details" << endl;
    cout << "Invoice Number     : " << invoice_num << endl;
    cout << "Shipping Type      : " << shippingType << endl;
    cout << "Purpose            : " << purpose << endl;
    cout << "Description        : " << description << endl;
    cout << "Quantity           : " << quantity << endl;
    cout << "Unit               : " << unit << endl;
    cout << "Weight per Item    : " << weightPerItem << " kg" << endl;
    cout << "Value              : RM " << value << endl;
    cout << "Origin             : " << p_origin <<endl<<endl;
    }
};

class Packaging {
private:
    int choice3;
    int quantity;
    double weight;
    double length;
    double width;
    double height;

    void setDimension(double l,double wd,double h){
        length=l;
        width=wd;
        height=h;
    }
public:
    Packaging()=default;
    Packaging(int q, double w, double l, double wd, double h,int ch) {
        quantity=q;
        weight=w;
        length=l;
        width=wd;
        height=h;
        choice3=ch;
    }
    void setQuantity(int q) {
        quantity = q;
    }
    void setWeight(double w) {
        weight = w;
    }
    void setChoice(int ch){
        choice3=ch;
    }
    void genPackage()
    {
        cout<<"Packaging List"<<endl<<endl;
        cout<<"   Type                  Size(cm)   "<<endl;
        cout<<"1. Box 1 - Shoe Box      33.7*18.2*8.1"<<endl;
        cout<<"2. Box 2                 33.7*32.2*9.2"<<endl;
        cout<<"3. Box 3 - Jumbo Small   34.0*33.0*35.0"<<endl;
        cout<<"4. Box 4                 48.1*40.4*38.9"<<endl;
        cout<<"5. Box 5 - Jumbo Large   55.0*45.0*41.0"<<endl;
        cout<<"6. Large Flyer           48.0*38.0*1.0"<<endl;
        cout<<"7. Standard Flyer        40.0*30.0*1.0"<<endl;
        cout<<"8. Tube(Large)           97.6*17.6*15.2"<<endl;
        cout<<"9. Your Own Package      Customize"<<endl<<endl;

        cout<<"Enter your choice: ";
        cin>>choice3;
        cout<<"Quantity: ";
        cin>>quantity;
        cout<<"Weight: ";
        cin>>weight;

        switch (choice3) {
        case 1: setDimension(33.7, 18.2, 8.1); break;
        case 2: setDimension(33.7, 32.2, 9.2); break;
        case 3: setDimension(34.0, 33.0, 35.0); break;
        case 4: setDimension(48.1, 40.4, 38.9); break;
        case 5: setDimension(55.0, 45.0, 41.0); break;
        case 6: setDimension(48.0, 38.0, 1.0); break;
        case 7: setDimension(40.0, 30.0, 1.0); break;
        case 8: setDimension(97.6, 17.6, 15.2); break;
        case 9:
            cout << "Length: ";
            cin >> length;
            cout << "Width: ";
            cin >> width;
            cout << "Height: ";
            cin >> height;
            setDimension(length, width, height);
            break;
        default:
            cout << "Invalid Choice\n";
            break;
        }
    }
    int getQuantity(){
        return quantity;
    }
    double getWeight(){
        return weight;
    }
    double getLength(){
        return length;
    }
    double getWidth(){
        return width;
    }
    double getHeight(){
        return height;
    }
    void DisplayPackage() {
        cout<<"Quantity: "<<quantity<<endl;
        cout<<"Weight: "<<weight<<endl;
        cout<<"Dimension: "<<length<<"x"<<width<<"x"<<height<<"cm"<<endl;
        cout<<"-----------------------------------------------------------"<<endl;
    }
};

//link with shipment
class PickUp{
private:
    int earlyTime;
    int lateTime;
    string place;
    string instruction;
public:
    PickUp(int a,int b,string p,string in){
        earlyTime=a;
        lateTime=b;
        place=p;
        instruction=in;
    }
    int getEarlyTime(){
        return earlyTime;
    }
    int getLateTime(){
        return lateTime;
    }
    string getPlace(){
        return place;
    }
    string getIns(){
        return instruction;
    }
    double totalWeight(vector<Packaging>& vr1){
        double totalWeight=0.0;
        for(int i=0;i<vr1.size();i++)
            totalWeight+=vr1[i].getWeight();
        return totalWeight;
    }
    void displayPickupDetails(vector<Packaging>& vr1){
        cout<<"Pickup Time: "<<earlyTime<<" - "<<lateTime<<endl;
        cout<<"Total weight: "<<totalWeight(vr1)<<endl;
        cout<<"Place: "<<place<<endl;
        cout<<"Instruction: "<<instruction<<endl;
    }
};

int PickupMenu(){
    int choice;
    cout<<"How do you want to provide your shipment?"<<endl;
    cout<<"1. Schedule a courier pickup"<<endl;
    cout<<"2. I do not need a pickup"<<endl;
    cout<<"3. Drop off at our service point"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    if(choice<1 || choice>3){
        cout<<"Invalid choice.\nEnter your choice: ";
        cin>>choice;
    }
    return choice;
}



class ShippingCost {
private:
    double ratePerKg;
    double handlingFees;
    double fuelSurcharge;
    double baseCost;
    double volWeight;
    double weight;
    double length;
    double width;
    double height;
    bool addGoGreen;
    bool addInsurance;
    bool addSignature;
    double chargeableWeight;
    double insuranceCost;
    double goGreenCost;
    double signatureCost;
    double totalCost;
public:
    ShippingCost(){
        ratePerKg = 25.0;
        handlingFees = 200.0;
        volWeight = 0.0;
        insuranceCost = 0.0;
        goGreenCost = 0.0;
        signatureCost = 0.0;
        totalCost = 0.0;
    }
    void setPackageDetails(double w, double l, double wd, double h) {
        weight = w;
        length = l;
        width = wd;
        height = h;
    }
    void setAddOns(bool green, bool insu, bool sign) {
        addGoGreen = green;
        addInsurance = insu;
        addSignature = sign;
    }
    void calculateCosts() {
        // Volumetric Weight
        if (length <= 0 || width <= 0 || height <= 0)
            volWeight = 0.0;
        else
            volWeight = (length * width * height) / 6000.0;

        chargeableWeight=(weight > volWeight) ? weight : volWeight;
        baseCost = chargeableWeight* ratePerKg;
        fuelSurcharge = (15.0 / 100.0) * baseCost;

        //Insurance
        if (!addInsurance)
            insuranceCost = 0.0;
        else{
            double baseInsurance = (3.0 / 100.0) * baseCost;
            insuranceCost = (baseInsurance < 25.0) ? 25.0 : baseInsurance;
        }

        goGreenCost = addGoGreen ? 10.00 : 0.0;
        signatureCost = addSignature ? 15.00 : 0.0;

        totalCost = baseCost + fuelSurcharge + handlingFees + goGreenCost + insuranceCost + signatureCost;
    }

    void displayCosts() {
        cout << "\n--- Air Freight Cost Calculation ---\n";
        cout << fixed << setprecision(2);
        cout << "Actual Weight (kg)      : " << weight << endl;
        cout << "Volumetric weight (kg)  : " << volWeight << endl;
        cout << "Chargeable weight (kg)  : " << (weight > volWeight ? weight : volWeight) << endl <<endl;
        cout << "Base cost (RM)          :" << baseCost << endl;
        cout << "Fuel Surcharge (RM)     : " << fuelSurcharge << endl;
        cout << "Handling Fee (RM)       : " << handlingFees << endl;
        cout << "GoGreen Plus (RM)       : " << goGreenCost << endl;
        cout << "Insurance cost (RM)     : " << insuranceCost << endl;
        cout << "Signature cost (RM)     : " << signatureCost << endl;
        cout << "----------------------------" << endl;
        cout << "Total cost (RM)         : " << totalCost << endl;
    }
};

class Payment {
private:
    int paymentOption;
    int cvc;
    string SST;
    string BRN;
    string taxNum;
    string ic;
    string bank;
    string cardNum;
    string expiryMonth;
public:
    Payment()=default;
    void business(string s,string b,string tax){
        SST=s;
        BRN=b;
        taxNum=tax;
    }
    void privatePerson(string id){
        ic=id;
    }
    void paymentDetails(string bn,string cn,int c,string em){
        bank=bn;
        cardNum=cn;
        cvc=c;
        expiryMonth=em;
    }
};

class CustomDocument:public Person{
private:
    string signerName;
    string signerTitle;
public:
    CustomDocument(string n,string ti){
        signerName=n;
        signerTitle=ti;
    }
    void setSignerName(string n){
        signerName=n;
    }
    void setSignerTitle(string t){
        signerTitle=t;
    }
    string getSignerName(){
        return signerName;
    }
    string getSignerTitle(){
        return signerTitle;
    }
};

int main()
{
    int choice;
    string origin,destination,type;
    double weight,width,length,height;
    int pickupDate;
    string firstName, lastName, company, country, address, state, email;
    int postcode, contactNum;
    int choice1=0,choice2=0,unit,qty;
    string desc,org;
    double value,w;
    int shipDay, shipMonth, shipYear;

    cout<<"Welcome to  Aseana Parcels!!"<<endl;
    cout<<"We provide courier service to 15 countries in Asia which include ";
    cout<<"Singapore, Thailand, Indonesia, Brunei, Vietnam, Laos, Cambodia, ";
    cout<<"Philippines, Myanmar, India, China, Bangladesh, Nepal, Sri Lanka, Maldives."<<endl<<endl;

    cout<<"Please enter the below details: "<<endl;
    do{
        cout<<"I am shipping as a..."<<endl;
        cout<<"1. Private Person"<<endl;
        cout<<"2. Business"<<endl;
        cin>>choice;

        switch(choice){
        case 1:
            type="Private";
            break;
        case 2:
            type="Business";
            break;
        default:
            cout<<"Please enter a valid choice."<<endl;
            break;
        }
    }while(choice!=1 || choice!=2)

    cout<<"Origin: ";
    cin>>origin;
    cout<<"Destination: ";
    cin>>destination;


    if(type=="Private"){
        do{
        cout<<"Weight: ";
        cin>>weight;
        if(weight>70)
            cout<<"Please enter a weight up to 70kg."<<endl;
        }while(weight>70)

        cout<<"If you are not sure with the size, you may refer to below details."<<endl;
        cout<<"A4 Envelope: 32*24*1 cm"<<endl;
        cout<<"Book: 23*14*4 cm"<<endl;
        cout<<"Shoe Box: 35*20*15 cm"<<endl;
        cout<<"Moving Box: 75*35*35 cm"<<endl;

        cout<<"Dimension"<<endl;
        do{
            cout<<"Width: ";
            cin>>width;
            if(width>80)
                cout<<"Please enter a width up to 80cm."<<endl;
        }while(width>80)
        do{
            cout<<"Length: ";
            cin>>length;
            if(length>80)
                cout<<"Please enter a width up to 120cm."<<endl;
        }while(length>80)
        do{
            cout<<"Height: ";
            cin>>height;
            if(height>80)
                cout<<"Please enter a width up to 80cm."<<endl;
        }while(height>80)
    }
    else{
        do{
        cout<<"Weight: ";
        cin>>weight;
        if(weight>150)
            cout<<"Please enter a weight up to 70kg."<<endl;
        }while(weight>150)

        cout<<"If you are not sure with the size, you may refer to the details below."<<endl;
        cout<<"A4 Envelope: 32*24*1 cm"<<endl;
        cout<<"Book: 23*14*4 cm"<<endl;
        cout<<"Shoe Box: 35*20*15 cm"<<endl;
        cout<<"Moving Box: 75*35*35 cm"<<endl;
        cout<<"Pallet: 110*110 cm"<<endl;
        cout<<"Cargo: 230*230*590 cm"<<endl;

        cout<<"Dimension"<<endl;
        do{
            cout<<"Width: ";
            cin>>width;
            if(width>250)
                cout<<"Please enter a width up to 80cm."<<endl;
        }while(width>250)
        do{
            cout<<"Length: ";
            cin>>length;
            if(length>600)
                cout<<"Please enter a width up to 120cm."<<endl;
        }while(length>600)
        do{
            cout<<"Height: ";
            cin>>height;
            if(height>250)
                cout<<"Please enter a width up to 80cm."<<endl;
        }while(height>250)
    }

    // Shipment Date, Pick up Date, Delivery Date
    cout<<"Shipment Date"<<endl;
    cout<<"Day: ";
    cin>>day;
    cout<<"Month: ";
    cin>>month;
    cout<<"Year: ";
    cin>>year;

    Shipment sm1(origin,destination,weight,length,width,height,day,month,year);

    cout<<"Estimated Pick Up Date: "<<sm1.generatePickupdate()<<endl; //add function later
    cout<<"Estimated delivery Date: "<<sm1.generateDeliDate()<<endl; //add function later

    // Shipping Cost
    ShippingCost sc1;
    sc1.setPackageDetails(weight, length, width, height);

    bool goGreen, insurance, signature;
    cout << "Do you want add on GoGreen Plus? (1 for Yes, 0 for No): ";
    cin >> goGreen;
    cout << "Do you want add on Insurance? (1 for Yes, 0 for No): ";
    cin >> insurance;
    cout << "Do you want add on signature service (RM 15)? (1 for Yes, 0 for No): ";
    cin >> signature;

    sc1.setAddOns(goGreen, insurance, signature);
    sc1.calculateCosts();
    sc1.displayCosts();

    // Sender Details
    cout<<"Enter Sender Details"<<endl;
    cout<<"First Name: ";
    cin>>fn;
    cout<<"Last Name: ";
    cin>>ln;
    cout<<"Type (private/business): ";
    cin>>t;
    cout<<"Company: (if private, enter N/A)";
    getline(cin,com);
    cout<<"Country: ";
    getline(cin,ctry);
    cout<<"Address: ";
    getline(cin,add);
    cout<<"Postcode: ";
    cin>>p;
    cout<<"State: ";
    getline(cin,s);
    cout<<"Email: ";
    cin>>e;
    cout<<"Contact Number: ";
    cin>>c;

    Sender s1(fn,ln,com,add,c,p,e,t,ctry,s);

    //Receiver Details
    cout<<"Enter Receiver Details"<<endl;
    cout<<"First Name: ";
    cin>>fn;
    cout<<"Last Name: ";
    cin>>ln;
    cout<<"Type (private/business): ";
    cin>>t;
    cout<<"Company: (if private, enter N/A)";
    getline(cin,com);
    cout<<"Country: ";
    getline(cin,ctry);
    cout<<"Address: ";
    getline(cin,add);
    cout<<"Postcode: ";
    cin>>p;
    cout<<"State: ";
    getline(cin,s);
    cout<<"Email: ";
    cin>>e;
    cout<<"Contact Number: ";
    cin>>c;

    Receiver r1(fn,ln,com,add,c,p,e,t,ctry,s);

    //Shipment Details
    cout<<"Shipment Details"<<endl;
    cout<<"What are you shipping?"<<endl;
    cout<<"1. Documents"<<endl;
    cout<<"2. Packages"<<endl;
    cout<<"3. Pallets"<<endl;
    cout<<"4. Cargo"<<endl;
    cout<<"5. Containers"<<endl;

    while(choice1<1 || choice1>5){
        cout<<"Enter your choice: ";
        cin>>choice1;

    }

    cout<<"What is the purpose of your shipment?"<<endl;
    cout<<"1. Gift"<<endl;
    cout<<"2. Commercial"<<endl;
    cout<<"3. Personal, Not for Resale"<<endl;
    cout<<"4. Sample"<<endl;
    cout<<"5. Return"<<endl;
    cout<<"6. Temporary Export"<<endl;

    while(choice2<1 || choice2>6){
        cout<<"Enter your choice: ";
        cin>>choice2;
    }

    cout<<"Description of product: "<<endl;
    getline(cin,desc)
    cout<<"Quantity: "<<endl;
    cin>>qty;
    cout<<"Units (How the item is packed): "<<endl;
    cin>>unit;
    cout<<"Value (RM Per Item): "<<endl;
    cin>>value;
    cout<<"Weight (kg Per Item):"<<endl;
    cin>>w;
    cout<<"Where is the item made?"<<endl;
    getline(cin,org);

    srand(time(0));
    int invoiceNumber=10000000+rand()%90000000;

    ShipmentDetail sd1(choice1,choice2,desc,qty,unit,w,value,org,invoiceNumber);
    sd1.Display();

    // Package Details
    vector<Packaging> p1;
    char addMore;
    do{
        Packaging newPackage;
        newPackage.genPackage();
        p1.push_back(newPackage);
        cout<<"Do you want to add another package? (Y/N): "<<endl;
        cin>>addMore;
    }while(addMore=='Y'||addMore=='y');

    cout<<"\nPackages Details"<<endl;
    for(int i=0;i<p1.size();i++){
        cout<<"Package "<<(i+1)<<" "<<endl;
        p1[i].DisplayPackage();
    }

    // Shipment Date
    sm1.displayAllDates();
    cout<<"Confirm? (Y/N)"<<endl;
    cin>>choice9;

    if(choice9!='Y'||choice9!='y'){
        cout<<"Enter a shipment date: "<<endl;
        cout<<"Date: "
        cin>>shipDay;
        cout<<"Month (in numbers): ";
        cin>>shipMonth;
        cout<<"Year: ";
        cin>>shipYear;

        sm1.setShipDay(shipDay);
        sm1.setShipMonth(shipMonth);
        sm1.setShipYear(shipYear);

        sm1.displayAllDates();
        cout<<"Confirm? (Y/N) "<<endl;
    }

    // Shipping Cost
    sc1.displayCosts();

    // Custom Documents
    string sName,sTitle;
    cout<<"Custom Invoice"<<endl;
    cout<<"Please enter details"<<endl;
    cout<<"Signer's Name: "<<endl;
    cin>>sName;
    cout<<"Signer's Title: "<<endl;
    cin>>sTitle;
    CustomDocument cd1(sName,sTitle);
    cout<<"Kindly remember to print out this custom invoice and sign it, along with any other custom documents. "<<endl;
    cout<<"Then provide them with your shipment."<<endl;

    // Pick Up Details
    int pickUpChoice,earlyT,lateT;
    string pickUpPlace,instruction,method;
    pickUpChoice=PickupMenu();

    switch(pickUpChoice){
        case 1:
            cout<<"Pick Up Time (Available from 1030-1800)"<<endl;
            cout<<"*Please allow at least 60 minutes for our courier to arrive and pick up."<<endl;
            cout<<"Enter the time in military time (EX: 8am:0800, 1pm: 1300)"<<endl;

            // get the pickup time
            cout<<"Earliest Time: ";
            cin>>earlyT;
            while(earlyT<1030 || earlyT>1700){
                cout<<"Please enter time between 1030 to 1700: "<<endl;
                cin>>earlyT;
            }
            cout<<"Latest Time: ";
            cin>>lateT;
            while(lateT<1130 || lateT>1800 || (lateT-earlyT<100)){
                if(lateT-earlyT<100)
                    cout<<"Latest time must be at least 1 hour later than the earliest time."<<endl;
                else{
                    cout<<"Please enter time between 1130 to 1800: "<<endl;
                    cin>>lateT;
                }
            }

            cin.ignore();
            cout<<"Place for courier pick up the shipment: ";
            getline(cin,pickUpPlace);
            cout<<"Any Instructions: "<<endl;
            getline(cin,instruction);

            PickUp pk1(earlyT,lateT,pickUpPlace,instruction);
            pk1.displayPickupDetails(p1);
            break;

        case 2:
            cout<<"You have chosen no pickup service."<<endl;
            break;

        case 3:
            cout<<"You have chosen to drop off at our service point."<<endl;
            break;
    }

    //Payment
    int paymentOption,next-0,approve=0,cvc;
    string SST,BRN,taxNum,ic,bank,cardNum,expiryMonth;
    Payment pm1;
    cout<<"Shipment Cost Summary"<<endl;
    sc1.displayCosts();

    do{
        cout<<"Payment Option"<<endl;
        cout<<"1. Visa"<<endl;
        cout<<"2. MasterCard"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>paymentOption;
        if(paymentOption<1 || paymentOption>2){
            cout<<"Invalid choice."<<endl;
            cout<<"Enter your choice: "<<endl;
            cin>>paymentOption;
        }

        cout<<"\nBilling Information"<<endl;
        s1.DisplaySender();
        if(s1.getType()=="Business"){
            cout<<"SST Registration Number (Ex: W12345678901234): "<<endl;
            cin>>SST;
            cout<<"Business Registration Number (Ex:202412345678): "<<endl;
            cin>>BRN;
            cout<<"Tax Identification Number (Ex:C1234567890): "<<endl;
            cin>>taxNum;
            pm1.business(SST,BRN,taxNum);
        }
        else{
            cout<<"NRIC Number (without space or dash sign): "<<endl;
            cin>>ic;
            pm1.privatePerson(ic);
        }

        cout<<"Accept & Pay (1/0)?"<<endl;
        cin>>next;
    }while(!next)

    cout<<"Payment Details"<<endl;
    cout<<"Bank: "<<endl;
    cin>>bank;
    cout<<"Card Number (16 digits): "<<endl;
    cin>>cardNum;
    cout<<"CVC (3 digits behind the card): "<<endl;
    cin>>cvc;
    cout<<"Expiry Month (Ex: 2024/11): "<<endl;
    cin>>expiryMonth;
    pm1.paymentDetails(bank,cardNum,cvc,expiryMonth);

    do{
        cout<<"Processing...\n"<<endl;
        cout<<"Kindly approve transaction on your device."<<endl;
        cout<<"If done, please enter 1"<<endl;
        cin>>approve;
    }while(!approve)

    cout<<"Payment Successful!!"<<endl;

    return 0;
}
