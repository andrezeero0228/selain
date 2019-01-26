/*
 * Copyright (c) 2019, Rauli Laine
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef SELAIN_TAB_HPP_GUARD
#define SELAIN_TAB_HPP_GUARD

#include <selain/tab-label.hpp>
#include <selain/view.hpp>
#include <selain/web-context.hpp>
#include <selain/web-settings.hpp>

namespace selain
{
  /**
   * GTK widget which acts as container for contents of a single tab. For
   * convenience reasons it also acts as a view itself.
   */
  class Tab : public View
  {
  public:
    explicit Tab(
      const Glib::RefPtr<WebContext>& context,
      const Glib::RefPtr<WebSettings>& settings
    );

    /**
     * Returns the GTK widget used as label for the tab.
     */
    inline TabLabel& get_tab_label()
    {
      return m_tab_label;
    }

    /**
     * Returns the GTK widget used as label for the tab.
     */
    inline const TabLabel& get_tab_label() const
    {
      return m_tab_label;
    }

    void grab_focus();

    inline Mode get_mode() const
    {
      return m_top_view->get_mode();
    }

    inline void set_mode(Mode mode)
    {
      m_top_view->set_mode(mode);
    }

    inline void close()
    {
      signal_close().emit(*this);
    }

    inline void execute_script(const Glib::ustring& script,
                               ::GCancellable* cancellable = nullptr,
                               ::GAsyncReadyCallback callback = nullptr,
                               void* data = nullptr)
    {
      m_top_view->execute_script(script, cancellable, callback, data);
    }

    inline Glib::ustring get_uri() const
    {
      return m_top_view->get_uri();
    }

    inline void load_uri(const Glib::ustring& uri)
    {
      m_top_view->load_uri(uri);
    }

    inline void reload(bool bypass_cache = true)
    {
      m_top_view->reload(bypass_cache);
    }

    inline void stop_loading()
    {
      m_top_view->stop_loading();
    }

    inline void go_back_in_history()
    {
      m_top_view->go_back_in_history();
    }

    inline void go_forward_in_history()
    {
      m_top_view->go_forward_in_history();
    }

    inline void find(const Glib::ustring& text, bool forwards = true)
    {
      m_top_view->find(text, forwards);
    }

    inline void find_next()
    {
      m_top_view->find_next();
    }

    inline void find_previous()
    {
      m_top_view->find_previous();
    }

    inline void add_hint_char(Glib::ustring::value_type c)
    {
      m_top_view->add_hint_char(c);
    }

    inline void remove_hint_char()
    {
      m_top_view->remove_hint_char();
    }

    inline void activate_current_hint()
    {
      m_top_view->activate_current_hint();
    }

    Glib::RefPtr<View> split(
      const Glib::RefPtr<WebContext>& context,
      const Glib::RefPtr<WebSettings>& settings,
      Gtk::Orientation orientation = Gtk::ORIENTATION_HORIZONTAL
    );

  private:
    void on_top_view_closed(View& view);
    void on_mode_changed(View& view, Mode mode);
    void on_title_changed(View& view, const Glib::ustring& title);
    void on_favicon_changed(View& view, ::cairo_surface_t* icon);

  private:
    TabLabel m_tab_label;
    Glib::RefPtr<View> m_top_view;
  };
}

#endif /* !SELAIN_TAB_HPP_GUARD */
