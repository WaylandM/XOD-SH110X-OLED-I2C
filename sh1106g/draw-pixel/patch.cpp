#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto display = getValue<input_DEV>(ctx);
        auto x = getValue<input_X>(ctx);
        auto y = getValue<input_Y>(ctx);
        auto colour = getValue<input_COLOUR>(ctx);
        display->drawPixel(x, y, colour);
        emitValue<output_DONE>(ctx, 1);
    }
}
