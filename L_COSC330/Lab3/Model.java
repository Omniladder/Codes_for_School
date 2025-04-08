package com.example.calculator;

public class Model {
    private int number = 1;
    public void reset() {
        this.number = 1;
    }
    public void multiply(int val){
        this.number *= val;
    }
    public int get_num(){
        return this.number;
    }

}
