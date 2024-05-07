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

    int ref_line_ct = ref.size() + 4;
    int usr_line_ct = usr.size() + 4;

    while(ref_line_ct > usr_line_ct){

        safe_open(ascii_burger_txt, input_stream);

        int ref_item = ref.get_go_next();

        // Get item
        do{
            getline(input_stream, current_line, '\n');
        } while(current_line != ingredient_map.at(ref_item) && !input_stream.eof());

        // Get ref line & print
        if(current_line == "top_bun" || current_line == "bottom_bun"){
            do{
                getline(input_stream, current_line, '\n');
                ref_line_ct--; // Decrement line count
                if(current_line.back() == ascii_burger_delim){
                    current_line.pop_back();
                    std::cout << current_line << std::endl;
                    break; // Stop at delim
                }
                std::cout << current_line << std::endl;
            } while(current_line.back() != ascii_burger_delim && !input_stream.eof()); // Safety param, should stop from delim break
        }
        else{
            
            getline(input_stream, current_line, ascii_burger_delim);
            std::cout << current_line << std::endl;
            ref_line_ct--;

        }

        input_stream.close();

    }
    while(usr_line_ct > ref_line_ct){

        safe_open(ascii_burger_txt, input_stream);

        int usr_item = usr.get_go_next();

        // Get item
        do{
            getline(input_stream, current_line, '\n');
        } while(current_line != ingredient_map.at(usr_item) && !input_stream.eof());

        // Get ref line & print
        if(current_line == "top_bun" || current_line == "bottom_bun"){
            do{
                getline(input_stream, current_line, '\n');
                usr_line_ct--; // Decrement line count
                if(current_line.back() == ascii_burger_delim){
                    current_line.pop_back();
                    std::cout << current_line << std::endl;
                    break; // Stop at delim
                }
                std::cout << current_line << std::endl;
            } while(current_line.back() != ascii_burger_delim && !input_stream.eof()); // Safety param, should stop from delim break
        }
        else{
            
            getline(input_stream, current_line, ascii_burger_delim);
            std::cout << current_line << std::endl;
            usr_line_ct--;

        }

        input_stream.close();

    }
    while(ref_line_ct == usr_line_ct){

        safe_open(ascii_burger_txt, input_stream);

        int ref_item = ref.get_go_next();
        int usr_item = usr.get_go_next();

        do{
            getline(input_stream, current_line, '\n');
        } while(current_line != ingredient_map.at(ref_item) && !input_stream.eof());

        if(current_line == "top_bun" || current_line == "bottom_bun"){
            
        }

    }
}