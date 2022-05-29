#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto display = getValue<input_DEV>(ctx);
        auto x0 = getValue<input_X0>(ctx);
        auto y0 = getValue<input_Y0>(ctx);
        auto x1 = getValue<input_X1>(ctx);
        auto y1 = getValue<input_Y1>(ctx);
        auto x2 = getValue<input_X2>(ctx);
        auto y2 = getValue<input_Y2>(ctx);
        auto colour = getValue<input_COLOUR>(ctx);
        auto fill = getValue<input_FILL>(ctx);
        if (fill){
            display->fillTriangle(x0, y0, x1, y1, x2, y2, colour);
        }else{
            display->drawTriangle(x0, y0, x1, y1, x2, y2, colour);
        }
        emitValue<output_DONE>(ctx, 1);
    }
}
