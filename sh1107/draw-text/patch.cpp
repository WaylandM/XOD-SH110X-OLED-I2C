#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    void evaluate(Context ctx) {
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto display = getValue<input_DEV>(ctx);
        auto cursor_x = getValue<input_X>(ctx);
        auto cursor_y = getValue<input_Y>(ctx);
        auto xString = getValue<input_TEXT>(ctx);
        auto font_size = getValue<input_SIZE>(ctx);
        auto colour = getValue<input_COLOUR>(ctx);
        auto wrap = getValue<input_WRAP>(ctx);
        int N=length(xString) + 1;
        char cString[N];
        for(int i=0;i<N;i++)
        cString[i]=0;
        dump(xString, cString);
        // Use full 256 char 'Code Page 437' font
        display->cp437(true);
        display->setTextWrap(wrap);
        display->setCursor(cursor_x, cursor_y);
        display->setTextSize(font_size);
        display->setTextColor(colour);
        display->println(cString);
        emitValue<output_DONE>(ctx, 1);
    }
}
