#ifndef NV_FOCUS_STEALING_H
#define NV_FOCUS_STEALING_H


class Focusable;
namespace nv {
    /**
     * interface for things that will steal the focus,
     * and thus need to give it back on close
     */

    class FocusStealing {
        public:
            virtual ~FocusStealing() {}
            virtual bool close() = 0;
            virtual const std::shared_ptr<Focusable>& getPreviouslyFocusedWidget() const = 0;
    };
}

#endif
