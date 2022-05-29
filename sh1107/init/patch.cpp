// Declare that node raises errors
#pragma XOD error_raise enable

node {

    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto display = getValue<input_DEV>(ctx);
        auto address = getValue<input_ADDR>(ctx);
        if (!display->begin(address, true)) {
            raiseError(ctx);
            return;
        }
        emitValue<output_DONE>(ctx, 1);
    }
}
