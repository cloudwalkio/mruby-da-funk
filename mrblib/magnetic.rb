class Platform::Magnetic
  GEDI_MSR_STATUS_SUCCESS = 0
  SUCCESS = 1

  class << self
    attr_accessor :tracks
  end

  def self.open
    self.tracks = {}
    0 # SUCCESSFULLY OPEN
  end

  def self.close
    nil
  end

  def self.read
    hash = self._read
    ret  = hash.delete(:ret)
    if ret == GEDI_MSR_STATUS_SUCCESS
      ret = SUCCESS
      # For some reason separators come with the string, example: ;6799998900000060125=14122060123456789?:
      hash[:track2] = hash[:track2].to_s[1..-3]
      self.tracks = hash
    end
    ret
  end
end

