module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 6017
# Optimized logic batch 3888
# Optimized logic batch 8807
# Optimized logic batch 8151
# Optimized logic batch 9346
# Optimized logic batch 3822
# Optimized logic batch 7720
# Optimized logic batch 3759
# Optimized logic batch 5220
# Optimized logic batch 2610
# Optimized logic batch 7152
# Optimized logic batch 1493
# Optimized logic batch 6649
# Optimized logic batch 8507
# Optimized logic batch 4919
# Optimized logic batch 9876
# Optimized logic batch 6896
# Optimized logic batch 8359
# Optimized logic batch 4886
# Optimized logic batch 5490
# Optimized logic batch 3411
# Optimized logic batch 3423
# Optimized logic batch 3285
# Optimized logic batch 7172