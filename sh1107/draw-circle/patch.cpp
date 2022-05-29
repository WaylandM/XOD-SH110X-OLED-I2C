#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node{
    void evaluate(Context ctx) {
    
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto display = getValue<input_DEV>(ctx);

        auto x = getValue<input_X>(ctx);
        auto y = getValue<input_Y>(ctx);
        auto radius = getValue<input_R>(ctx);
        auto colour = getValue<input_COLOUR>(ctx);
        auto fill = getValue<input_FILL>(ctx);

        if (fill){
            display->fillCircle(x, y, radius, colour);
        }else{
            display->drawCircle(x, y, radius, colour);
        }

        emitValue<output_DONE>(ctx, 1);
    }
}
