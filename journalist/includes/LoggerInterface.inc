<?php namespace journalist\includes;

/**
 * Interface LoggerInterface
 * @package journalist\includes
 */
interface LoggerInterface {
  /**
   * This is a level for external systems that can look at your system and determine for sure that it does not work completely,
   * or its self-diagnosis does not work.
   * @param string $message
   * @param array $context
   * @return void
   */
   function emergency(string $message, array $context = []);

  /**
   * System itself can diagnose its condition, for example,
   * by a scheduled task, and as a result record an event with this level.
   *
   * These can be checks of connected resources or something specific,
   * for example, the balance on the account of the external resource used.
   * @param string $message
   * @param array $context
   * @return void
   */
   function alert(string $message, array $context = []);

  /**
   * An event when a system component fails,
   * which is very important and should always work.
   * It already depends a lot on what the system is doing.
   * It is suitable for events that it is important to find out about quickly, even if it happened only once.
   * @param string $message
   * @param array $context
   * @return void
   */
   function critical(string $message, array $context = []);

  /**
   * An event has occurred about which,
   * if repeated soon, you need to report.
   *
   * Failed to perform an action that must be performed,
   * but such an action does not fall under the critical description.
   *
   * For example, it was not possible to save the user's avatar at his request,
   * but the system is not an avatar service, but a chat system.
   * @param string $message
   * @param array $context
   * @return void
   */
   function error(string $message, array $context = []);

  /**
   * Events, for immediate notification of which you need to collect a significant number of them over a period of time.
   * Failed to perform an action, the failure of which does not break anything serious.
   * These are still errors that can wait for the work schedule to fix.
   *
   * For example, the user's avatar could not be saved,
   * and the system is an online store.
   *
   * Notification of them is needed (at a high frequency) to learn about sudden anomalies,
   * because they can be symptoms of more serious problems.
   * @param string $message
   * @param array $context
   * @return void
   */
   function warning(string $message, array $context = []);

  /**
   * These are events that report deviations provided by the system,
   * which are part of the normal functioning of the system.
   *
   * For example, the user specified an incorrect password when logging in, the user did not fill in the patronymic,
   * but it is not necessary, the user bought the order for 0 rubles, but this is provided for in rare cases.
   *
   * Notification of them at a high frequency is also necessary,
   * since a sharp increase in the number of deviations may be the result of an error that urgently needs to be corrected.
   * @param string $message
   * @param array $context
   * @return void
   */
   function notice(string $message, array $context = []);

  /**
   * Events, the occurrence of which informs about the normal functioning of the system.
   *
   * For example, a user has registered, a user has purchased a product, a user has left a review.
   *
   * Notification of such events should be configured in reverse:
   * if an insufficient number of such events occurred over a period of time,
   * then you need to notify, because their decrease could be caused as a result of an error.
   * @param string $message
   * @param array $context
   * @return void
   */
   function info(string $message, array $context = []);

  /**
   * Events for debugging a process in the system.
   *
   * If you add enough data to the context of the event,
   * you can diagnose the problem, or conclude that the process is functioning properly in the system.
   *
   * For example, a user opened a product page and received a list of recommendations.
   *
   * Significantly increases the number of events sent,
   * so it is acceptable to remove logging of such events after a while.
   * As a result, the number of such events in normal operation will be variable,
   * then monitoring for notification of them can not be connected.
   * @param string $message
   * @param array $context
   * @return void
   */
   function debug(string $message, array $context = []);
}
