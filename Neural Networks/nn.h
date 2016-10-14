#ifndef NNCore

class Neuron{
    public:
        Neuron(){
            input = 0;
            output = 0;
        }

        void processing(long double weight, long double treshold,long double Nf){
            if(input * weight >= treshold)
                output = Nf;  
            else output = 0;
        }
      
        long double input, output;
    private:
};

class Synapse{
    public:
        Synapse(Neuron *_a, Neuron *_b, long double def_w = 1){
            a = _a;
            b = _b;
            weight = def_w;
        }
 
        void processing(){
            a->processing(weight,0.5,a->input);
            b->input += (a->output * weight);
        }
        
        long double weight;
    private:
        Neuron *a, *b;
        
};

#endif
