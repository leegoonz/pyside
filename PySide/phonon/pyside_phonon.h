#ifndef PYSIDE_PHONON
#define PYSIDE_PHONON

#include <QObject>
#include <phonon/backendcapabilities.h>

QT_BEGIN_NAMESPACE

namespace Phonon
{
namespace BackendCapabilities
{
    class NotifierWrapper : public QObject
    {
        public:

            inline static NotifierWrapper* notifier() {
                Notifier* notifier = BackendCapabilities::notifier();

                if (notifier != m_notifier) {
                    delete m_instance;
                    m_instance = new NotifierWrapper(notifier);

                }

                return m_instance;
            }

            inline const QMetaObject* metaObject() const { return m_notifier->metaObject(); }

        private:
            static NotifierWrapper* m_instance;
            static Notifier* m_notifier;

            NotifierWrapper(Notifier* notifier) { m_notifier = notifier; }
            NotifierWrapper() {}
    };
}
}

QT_END_NAMESPACE

#endif
