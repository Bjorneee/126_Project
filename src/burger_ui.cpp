#include "burger_ui.h"

void safe_open(const string& filename, ifstream& ifs) {

    ifs.open(filename);
    if(ifs.fail()){
        cerr << "\nCould not open: " << filename << endl;;
        exit(-1);
    }
}

void display_burgers(const Burger& reference_burger, const Burger& user_burger, const map<int, string>& ingredient_map) {

    ifstream input_stream;

    string current_line;
    stack<string> print_stack;

    Burger ref = reference_burger;
    Burger usr = user_burger;

    while(ref.size() > usr.size()){

        int ref_item = ref.get_go_next();

        safe_open(ascii_burger_txt, input_stream);

        do{
            getline(input_stream, current_line, '\n');
        } while(current_line != ingredient_map.at(ref_item) && !input_stream.eof());

        getline(input_stream, current_line, ascii_burger_delim);

        cout << current_line << endl;

        input_stream.close();
    }
    while(ref.size() == usr.size() && ref.size() > 0){

        int ref_item = ref.get_go_next();
        int usr_item = usr.get_go_next();

        bool sprite_end = false;

        while(!sprite_end){

            safe_open(ascii_burger_txt, input_stream);
            
            do{
                getline(input_stream, current_line, '\n');
            } while(current_line != ingredient_map.at(ref_item) && !input_stream.eof());
        }

    }
}