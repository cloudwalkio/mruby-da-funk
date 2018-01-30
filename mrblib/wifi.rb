
class Platform::Network::Wifi
  GEDI_WIFI_STATUS_AP_CONNECTED     = 2
  GEDI_WIFI_STATUS_SCANNING         = 8
  GEDI_WIFI_STATUS_AP_CONNECTING    = 16
  GEDI_WIFI_STATUS_CONNECTING       = 32
  GEDI_WIFI_STATUS_SENDING          = 64
  GEDI_WIFI_STATUS_RECEIVING        = 128
  GEDI_WIFI_STATUS_DISCONNECTING    = 256
  GEDI_WIFI_STATUS_AP_DISCONNECTING = 512

  class << self
    attr_accessor :rssi, :authentication, :password, :essid, :bssid, :channel, :mode, :cipher
    attr_reader :media
    @media = :wifi
  end

  AUTH_NONE_OPEN       = ""
  AUTH_WPA_PSK         = "wpapsk"
  AUTH_WPA_EAP         = "wpaeap"
  AUTH_WPA2_PSK        = "wpa2psk"
  AUTH_WPA2_EAP        = "wpa2eap"
  #NOT SUPPORTED
  AUTH_NONE_WEP        = "2"
  AUTH_NONE_WEP_SHARED = "3"
  AUTH_IEEE8021X       = "4"
  AUTH_WPA_WPA2_PSK    = "7"
  AUTH_WPA_WPA2_EAP    = "8"

  PARE_CIPHERS_NONE   = ""
  PARE_CIPHERS_CCMP   = "ccmp"
  PARE_CIPHERS_TKIP   = "tkip"
  PARE_CIPHERS_CCMPTKIP = "ccmptki"
  #NOT SUPPORTED
  PARE_CIPHERS_WEP64  = 0x01.chr
  PARE_CIPHERS_WEP128 = 0x02.chr
  PARE_CIPHERS_WEPX   = 0x04.chr

  MODE_STATION = "Managed"
  #NOT SUPPORTED
  MODE_IBSS    = "1"

  AUTHENTICATIONS = {
    "open"       => AUTH_NONE_OPEN,
    "wep"        => AUTH_NONE_WEP,
    "wep_shared" => AUTH_NONE_WEP_SHARED,
    "iEEE8021X"  => AUTH_IEEE8021X,
    "wpapsk"     => AUTH_WPA_PSK,
    "wpaeap"     => AUTH_WPA_EAP,
    "wpawpa2psk" => AUTH_WPA_WPA2_PSK,
    "wpawpa2eap" => AUTH_WPA_WPA2_EAP,
    "wpa2psk"    => AUTH_WPA2_PSK,
    "wpa2eap"    => AUTH_WPA2_EAP
  }
  INVERTED_AUTHENTICATIONS = AUTHENTICATIONS.invert

  CIPHERS = {
    "none"     => PARE_CIPHERS_NONE,
    "wep64"    => PARE_CIPHERS_WEP64,
    "wep128"   => PARE_CIPHERS_WEP128,
    "wepx"     => PARE_CIPHERS_WEPX,
    "ccmp"     => PARE_CIPHERS_CCMP,
    "tkip"     => PARE_CIPHERS_TKIP,
    "ccmptkip" => PARE_CIPHERS_CCMPTKIP
  }
  INVERTED_CIPHERS = CIPHERS.invert

  MODES = {
    "station" => MODE_STATION,
    "ibss"    => MODE_IBSS
  }
  INVERTED_MODES = MODES.invert

  def self.init(options = {})
    @essid          = options[:essid].to_s
    @bssid          = options[:bssid].to_s
    @mode           = MODES[options[:mode]].to_s
    @authentication = AUTHENTICATIONS[options[:authentication]].to_s
    @cipher         = CIPHERS[options[:cipher]].to_s
    @password       = options[:password].to_s
    @channel        = options[:channel].to_s
    self.start
  end

  def self.type
    Network::NET_LINK_WIFI
  end

  def self.signal
    @rssi
  end

  def self.scan
    @aps = []
    self._scan
    @aps
  end

  def self.ap(_bssid, _essid, _mode, _channel, _rssi, _type_1, _groupcipher_1, _pairwiseciphers_1, _authentication_1)
    @aps ||= []
    @aps << {
      :essid          => _essid,
      :bssid          => _bssid,
      :channel        => _channel[-3..-2].to_i,
      :mode           => INVERTED_MODES[_mode],
      :rssi           => _rssi[0],
      :authentication => INVERTED_AUTHENTICATIONS["#{_type_1.downcase}#{_authentication_1.downcase}"],
      :cipher         => INVERTED_CIPHERS["#{_pairwiseciphers_1.downcase}"]
    }
  end

  def self.connected?
    connection = self._connected?
    ret = -1
    ret = 1 if (connection & GEDI_WIFI_STATUS_AP_CONNECTING) != 0
    ret = 0 if (connection & GEDI_WIFI_STATUS_AP_CONNECTED) != 0
    ret
  end
end

