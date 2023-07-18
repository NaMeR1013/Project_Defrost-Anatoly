#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void tempUpdate();
    float getCurrentTemp();

protected:
    ModelListener* modelListener;
    float DEFRcurrentTemperatureLeft;
};

#endif // MODEL_HPP
