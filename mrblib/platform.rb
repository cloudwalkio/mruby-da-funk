class Platform
  Network = ::Network if Kernel.const_defined? :Network
  IO      = ::IO

  class System
    class << self
      alias_method :restart, :reboot if self.respond_to? :reboot
    end
  end

  class IO
    DEFAULT_TIMEOUT = 30000

    class << self
      attr_accessor :timeout
    end
    self.timeout = DEFAULT_TIMEOUT

    # get_string c implementation.
    #
    # @param min [Fixnum] Minimum length of the input string.
    # @param max [Fixnum] Maximum length of the input string (127 bytes maximum).
    # @param mode [Symbol] Mode to input, check IO_INPUT_* variables.
    def self.get_string(min, max, mode = :letters)
      _gets(min, max, convert_input_type(mode), 0, 2)
    end
  end

  def self.screen_definition
    case System.model
    when "mp20"
      [22, 11]
    when "gpos400"
      [22, 22]
    else
      [22, 11]
    end
  end

  def self.icons_status_bar
    model = System.model.to_s
    [
      "./shared/background_#{model}.bmp", "./shared/wifi_#{model}.bmp",
      "./shared/gprs_#{model}.bmp", "./shared/battery_#{model}.bmp"
    ]
  end

  def self.define_device_modules
    Device.const_set(:EMV               , Platform::EMV)
    Device.const_set(:Pinpad            , Platform::EMV::Pinpad)
    Device::Network.const_set(:Gprs     , Platform::Network::Gprs)
    Device::Network.const_set(:Ethernet , Platform::Network::Ethernet)
    Device::Network.const_set(:Wifi     , Platform::Network::Wifi)
  end

  # Will be called at RunTime boot
  def self.setup
    Screen.setup(*screen_definition)
    self.define_device_modules
    require 'posxml_parser'
    require 'cloudwalk_handshake'
    CloudwalkHandshake.configure!
    self.setup_keyboard
    self.setup_status_bar
    self.setup_crypto
    Platform::Printer.start
  end

  def self.version
    "0.2.1"
  end

  def self.setup_keyboard
    menu_options = {
      :back_key          => Device::IO::F1,
      :back_key_label    => "    ",
      :forward_key       => Device::IO::ALPHA,
      :forward_key_label => "    "
    }

    menu_options[:forward_key] = Device::IO::F2 if System.model == "mp20"

    Device::IO.setup_keyboard(["qzQZ", "abcABC", "defDEF", "ghiGHI", "jklJKL",
                              "mnoMNO", "prsPRS", "tuvTUV", "wxyWXY", " .,_#@+!?"],
                             menu_options)
  end

  def self.setup_status_bar
    Platform::System.status_bar(*icons_status_bar)
    DaFunk::Helper::StatusBar.managment = false if DaFunk::Helper::StatusBar.respond_to?(:managment=)
  end

  def self.setup_crypto
    # TODO Reafactor, send it to DaFunk, maybe.
    Device::Crypto.define_singleton_method :dukpt_encrypt_buffer do |a,b|
      Platform::Crypto.dukpt_encrypt_buffer(a,b)
    end
  end
end
