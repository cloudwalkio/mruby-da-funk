class Platform
  class Touch
    # Get coodinates X and Y of the touch event
    #   This functions clean the queue before read
    #
    # @param timeout [Integer] Text to be printed.
    # @return [NilClass] nil if no event was detected and timeout expired.
    # @return [Array] [123, 25] ([X, Y]).
    def self.getxy(timeout = 10_000)
      hash = self._getxy(timeout)
      if hash["return"] == 1
        [hash["x"], hash["y"]]
      end
    end

    # Get coodinates X and Y of the touch event
    #   This functions don't clean the queue before read, so an event before
    #   this executions could be detected.
    #
    # @param timeout [Integer] Text to be printed.
    # @return [NilClass] nil if no event was detected and timeout expired.
    # @return [Array] [123, 25] ([X, Y]).
    def self.getxy_stream(timeout = 10_000)
      hash = self._getxy_stream(timeout)
      if hash["return"] == 1
        [hash["x"], hash["y"]]
      end
    end
  end
end

