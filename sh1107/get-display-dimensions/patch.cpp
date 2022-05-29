node {
    void evaluate(Context ctx) {
        auto display = getValue<input_DEV>(ctx);
        int16_t display_width, display_height;
        display_width = display->width();
        display_height = display->height();
        emitValue<output_WIDTH>(ctx, display_width);
        emitValue<output_HEIGHT>(ctx, display_height);
    }
}
