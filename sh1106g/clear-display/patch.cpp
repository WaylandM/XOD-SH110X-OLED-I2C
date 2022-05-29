#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto display = getValue<input_DEV>(ctx);
        display->clearDisplay();
        emitValue<output_DONE>(ctx, 1);
    }
}
