package com.example.calculator;


import android.view.View;
import android.widget.EditText;
import android.widget.TextView;


public class Controller{


    private Model total_state = new Model();
    private View view;

    public Controller(View view) {
        this.view = view;
    }

    private void update_total() {
        TextView total_view = (TextView) view.findViewById(R.id.total_value);
        total_view.setText(String.valueOf(total_state.get_num()));
    }

    public void clear(){
        total_state.reset();
        update_total();
    }
    public void multiply(){
        EditText input_text = (EditText) view.findViewById(R.id.number_input);
        String input = input_text.getText().toString();
        int number = Integer.parseInt(input);
        total_state.multiply(number);
        update_total();
    }


}
