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
        auto colour = getValue<input_COLOUR>(ctx);
        display->drawLine(x0, y0, x1, y1, colour);
        emitValue<output_DONE>(ctx, 1);
    }
}
