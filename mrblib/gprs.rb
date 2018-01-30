class Platform::Network::Gprs
  GEDI_GSM_NETSTATUS_ESTABLISHED   = 2
  GEDI_GSM_NETSTATUS_ESTABLISHING  = 16
  GEDI_GSM_NETSTATUS_CONNECTING    = 32
  GEDI_GSM_NETSTATUS_SENDING       = 64
  GEDI_GSM_NETSTATUS_RECEIVING     = 128
  GEDI_GSM_NETSTATUS_DISCONNECTING = 256
  GEDI_GSM_NETSTATUS_ONHOOKING     = 512

  GEDI_GSM_INFO_MANUFACTURER   = 0  # Modem manufacturer
  GEDI_GSM_INFO_VERSION        = 1  # Modem firmware version
  GEDI_GSM_INFO_MODEL          = 2  # Modem model
  GEDI_GSM_INFO_IMEI           = 3  # International Mobile Equipment Identity
  GEDI_GSM_INFO_IMSI           = 4  # International Mobile Subscriber Identifier (IMSI)
  GEDI_GSM_INFO_RSSI           = 5  # Received signal strength (0 to 5)
  GEDI_GSM_INFO_NITZ           = 6  # Network Identity and Time Zone
  GEDI_GSM_INFO_OPERATOR_NAME  = 7  # Enhanced Operator Name String
  GEDI_GSM_INFO_SIM_CCID       = 8  # SIM Card Identification number
  GEDI_GSM_INFO_CELL_ID        = 9  # Serving Cell ID in hexadecimal format
  GEDI_GSM_INFO_NEIGHBOR_CELLS = 10 # Neighbor cells informations
  GEDI_GSM_INFO_IP             = 11 # Local IP Address
  GEDI_GSM_INFO_GATEWAY        = 12 # Remote IP Address
  GEDI_GSM_INFO_DNS            = 13 # DNS server
  GEDI_GSM_INFO_SIGNAL         = 14 # Signal as 0 - 31
  GEDI_GSM_INFO_NET_MCC        = 15 # Serving Cell Mobile Country Code
  GEDI_GSM_INFO_NET_MNC        = 16 # Serving Cell Mobile Network Code
  GEDI_GSM_INFO_NET_LAC        = 17 # Serving Cell Location Area
  GEDI_GSM_INFO_NET_BSIC       = 18 # Serving Cell Base Station Identity Code
  GEDI_GSM_INFO_NET_CHANNEL    = 19 # Serving Cell ARFCN

  class << self
    attr_accessor :password, :user, :apn
    attr_reader :media
    @media = :gprs
  end

  def self.init(options = {})
    @apn      = options[:apn]
    @user     = options[:user]
    @password = options[:password]
    self.start
  end

  def self.type
    Network::NET_LINK_WL
  end

  def self.connect
    self._connect
  end

  def self.cell
    {
      :mcc => self.mcc,
      :mnc => self.mnc,
      :lac => self.lac,
      :cell_id => self.cell_id,
    }
  end

  def self.signal
    ret, value = self.info(GEDI_GSM_INFO_SIGNAL)
    if ret == 0 && !value.to_s.empty?
      (value.to_i * 3.228).to_i
    else
      0
    end
  end

  def self.connected?
    connection = self._connected?
    ret = -1
    ret = 1 if (connection & GEDI_GSM_NETSTATUS_CONNECTING) != 0
    ret = 0 if (connection & GEDI_GSM_NETSTATUS_ESTABLISHED) != 0
    ret
  end

  private
  def self.mcc
    ret, value = Platform::Network::Gprs.info(Platform::Network::Gprs::GEDI_GSM_INFO_NET_MCC)
    value if ret == 0
  end

  def self.mnc
    ret, value = Platform::Network::Gprs.info(Platform::Network::Gprs::GEDI_GSM_INFO_NET_MNC)
    value if ret == 0
  end

  def self.lac
    ret, value = Platform::Network::Gprs.info(Platform::Network::Gprs::GEDI_GSM_INFO_NET_LAC)
    value if ret == 0
  end

  def self.cell_id
    ret, value = Platform::Network::Gprs.info(Platform::Network::Gprs::GEDI_GSM_INFO_CELL_ID)
    value if ret == 0
  end
end

