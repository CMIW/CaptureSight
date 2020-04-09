#include <switch.h>
#include <ui/MainApplication.hpp>
#include <utils/I18N.hpp>

extern MainApplication::Ref mainApp;
extern std::shared_ptr<I18N> i18n;

int main() {
  setInitialize();
  dmntchtInitialize();
  dmntchtForceOpenCheatProcess();

  auto renderer = pu::ui::render::Renderer::New(SDL_INIT_EVERYTHING, pu::ui::render::RendererInitOptions::RendererNoSound,
                                                pu::ui::render::RendererHardwareFlags);
  mainApp = MainApplication::New(renderer);
  i18n = std::make_shared<I18N>();

  mainApp->Prepare();
  mainApp->ShowWithFadeIn();

  dmntchtExit();
  setExit();

  return 0;
}