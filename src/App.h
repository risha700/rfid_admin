//
// Created by Ahmed Shehab on 9/21/23.
//

#ifndef INTERFACE_APP_H
#define INTERFACE_APP_H

#include <gtkmm.h>
#include "LoginWindow.h"
#include "NetworkClient.h"
#include "ControlsWindow.h"

#ifndef AUTH_FS
#define AUTH_FS "/tmp/rfid.sys"
#endif


#ifdef APP_ENV
#define RFID_APP_ENV APP_ENV
#else
#define RFID_APP_ENV "PRODUCTION"
#endif



#include "AppLogger.h"

class App: public Gtk::Application
{
protected:
    App();
    virtual ~App();
    
    Glib::RefPtr<Gtk::Builder> m_refBuilder;


public:
    static Glib::RefPtr<App> create();
    bool is_authenticated=false;
    LoginWindow login_window;
    NetworkClient network_client;
    const char* environment=RFID_APP_ENV;
    std::shared_ptr<AppLogger> logger = AppLogger::getLogger();
    void on_login_state_change();
    void on_data_received(const std::string& data) const;
    bool on_time_out();

    static App* get_instance();
protected:
    // Override default signal handlers:
    void on_activate() override;
    void on_open(const Gio::Application::type_vec_files& files,
                 const Glib::ustring& hint) override;
    static App* instance;

private:
    auto * create_app_window();
    auto * create_login_window();
    

};
//NetworkClient* App::network_client = nullptr;

#endif //INTERFACE_APP_H
