#ifndef NNCore

class Neuron{
    public:
        Neuron(){
            input = 0;
            output = 0;
        }

        void processing(long double treshold,long double Nf){
            if(input >= treshold)
                output = N;   
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
            b->input += (a->output * weight);
            b->processing(0.1,b->input);
        }
        
        long double weight;
    private:
        Neuron *a, *b;
        
};

#endif
