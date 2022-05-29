#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto display = getValue<input_DEV>(ctx);
        auto invert_display = getValue<input_INV>(ctx);
        display->invertDisplay(invert_display);
        emitValue<output_DONE>(ctx, 1);
    }
}
