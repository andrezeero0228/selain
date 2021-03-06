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
#include <selain/theme.hpp>

namespace selain
{
  namespace theme
  {
    static const auto status_bar_style_provider = Gtk::CssProvider::create();
    static const auto entry_style_provider = Gtk::CssProvider::create();

    const Gdk::RGBA window_background("#262626");
    const Gdk::RGBA window_foreground("#b3deef");
    const Gdk::RGBA status_bar_background("#444444");
    const Gdk::RGBA status_bar_foreground("#a7d6f8");
    const Gdk::RGBA status_bar_error_background("#f43753");
    const Gdk::RGBA status_bar_error_foreground("#eeeeee");
    const Gdk::RGBA mode_bar_normal_background("#b3deef");
    const Gdk::RGBA mode_bar_normal_foreground("#282828");
    const Gdk::RGBA mode_bar_insert_background("#d7d75f");
    const Gdk::RGBA mode_bar_insert_foreground("#262626");

    const Glib::RefPtr<Gtk::CssProvider>&
    get_status_bar_style_provider()
    {
      static bool initialized = false;

      if (!initialized)
      {
        initialized = true;
        status_bar_style_provider->load_from_data(
          "label {\n"
          "  padding: 0.1em 0.4em;\n"
          "}\n"
        );
      }

      return status_bar_style_provider;
    }

    const Glib::RefPtr<Gtk::CssProvider>&
    get_command_entry_style_provider()
    {
      static bool initialized = false;

      if (!initialized)
      {
        initialized = true;
        entry_style_provider->load_from_data(
          "entry, .entry {\n"
          "  background: #262626;\n"
          "  border: none;\n"
          "  color: #eeeeee;\n"
          "  margin: 0;\n"
          "  outline: none;\n"
          "  padding: 0.2em;\n"
          "}"
        );
      }

      return entry_style_provider;
    }
  }
}
