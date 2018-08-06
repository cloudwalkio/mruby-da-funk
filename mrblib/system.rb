class Platform
  class System
    RET_OK = 0

    class << self
      alias_method :restart, :reboot if self.respond_to? :reboot
    end

    #Options for eStorage
    GEDI_FS_STORAGE_PRIVATE  = 0
    #Private storage  - Created files with this option will be accessible only to current application. When used to open an existing file, will be able to open only files created by the current application.
    GEDI_FS_STORAGE_PUBLIC   = 1
    #Public storage   - Created files with this option will be accessible by all applications in the device. When used to open an existing file, will be able to open files created by other applications. Extra care must be taken when writing to files, as it can overwrite files created by other applications. Also, reading operations should be validated as the file, being public, can be changed without the consent of the application.
    GEDI_FS_STORAGE_USB_DISK = 2
    #USB disk storage - Created files with this option will be accessible by all applications in the device. It is only accessible if USB port is in HOST mode.
    GEDI_FS_STORAGE_SD_CARD  = 3
    #SD Card storage  - Created files with this option will be accessible by all applications in the device.

    # Calls examples
    # Device::System.update("./shared/application.aip;system")
    # Device::System.update("./shared/application.p3a;system")
    # Device::System.update("./shared/main.zip;/")
    # Device::System.update("./shared/font.tar.gz;system")
    # Device::System.update("./shared/font.p3t;system")
    # Device::System.update("./shared/main.bmp;/shared")
    def self.update(path)
      file, type = path.split(";")

      if type == "system"
        if self.install(nil, path, nil)
          # set system update flag
        else
          ContextLog.info "System Update - Error [#{path}][#{ret_install.inspect}]"
          false
        end
      else
        true
        # copy files
      end
    end

    POWER_ADAPTER = 1
    POWER_USB     = 2
    POWER_BATTERY = 3

    def self.power_supply
      self._power_supply
    end

    def self.versions
      hash = Hash.new
      hash["OS"]     = self.os_version
      hash["SDK"]    = self.sdk_version
      hash["EMV"]    = Platform::EMV.version if Platform.const_defined? :EMV
      hash["Pinpad"] = self.pinpad_version
      hash
    end
  end
end
